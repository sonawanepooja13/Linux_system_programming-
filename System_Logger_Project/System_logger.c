//USAGE:
// ./myexe
// ./myexe /home
// ./myexe /home 5

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>
#include <sys/utsname.h>

//////////////////////////////////////////////////////////////////
// Global variables
//////////////////////////////////////////////////////////////////

static volatile sig_atomic_t stop_flag = 0;

typedef struct
{
    double cpu;
    double mem;
    double disk;
} Snapshot;

static Snapshot snap;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static char *disk_path = "/";
static int interval_sec = 2;

//////////////////////////////////////////////////////////////////
// CTRL+C handler
//////////////////////////////////////////////////////////////////

static void sigint_handler(int sig)
{
    (void)sig;
    write(STDOUT_FILENO,"\nMarvellous System Logger terminating...\n",40);
    stop_flag = 1;
}

//////////////////////////////////////////////////////////////////
// Timestamp helper
//////////////////////////////////////////////////////////////////

static void timestamp(char *out,size_t sz)
{
    time_t now=time(NULL);
    struct tm t;

    localtime_r(&now,&t);

    strftime(out,sz,"%Y-%m-%d %H:%M:%S",&t);
}

//////////////////////////////////////////////////////////////////
// SYSTEM INFORMATION
//////////////////////////////////////////////////////////////////

static void system_info(char *buffer,size_t size)
{
    char hostname[256];
    struct utsname sysinfo;
    long cores;
    unsigned long long mem_kb=0;

    gethostname(hostname,sizeof(hostname));

    uname(&sysinfo);

    cores=sysconf(_SC_NPROCESSORS_ONLN);

    FILE *fp=fopen("/proc/meminfo","r");

    if(fp)
    {
        fscanf(fp,"%*s %llu %*s",&mem_kb);
        fclose(fp);
    }

    double mem_gb=mem_kb/(1024.0*1024.0);

    snprintf(buffer,size,
    "---------------- System Information ----------------\n"
    "Hostname : %s\n"
    "Kernel   : %s %s\n"
    "CPU Cores: %ld\n"
    "RAM      : %.2f GB\n"
    "----------------------------------------------------\n",
    hostname,
    sysinfo.sysname,
    sysinfo.release,
    cores,
    mem_gb);
}

//////////////////////////////////////////////////////////////////
// CPU helper
//////////////////////////////////////////////////////////////////

static int read_cpu(unsigned long long *total,unsigned long long *idle_all)
{
    FILE *fp=fopen("/proc/stat","r");

    if(!fp) return -1;

    char line[512];

    if(!fgets(line,sizeof(line),fp))
    {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    unsigned long long user,nice,sys,idle,iowait,irq,softirq,steal;

    int n=sscanf(line,
    "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
    &user,&nice,&sys,&idle,&iowait,&irq,&softirq,&steal);

    if(n<4) return -1;

    *idle_all=idle+iowait;
    *total=user+nice+sys+idle+iowait+irq+softirq+steal;

    return 0;
}

static double cpu_percent()
{
    unsigned long long t1,i1,t2,i2;

    if(read_cpu(&t1,&i1)!=0) return 0.0;

    sleep(1);

    if(read_cpu(&t2,&i2)!=0) return 0.0;

    unsigned long long dt=t2-t1;
    unsigned long long di=i2-i1;

    if(dt==0) return 0.0;

    return ((double)(dt-di)/dt)*100.0;
}

//////////////////////////////////////////////////////////////////
// Memory usage
//////////////////////////////////////////////////////////////////

static double mem_percent()
{
    FILE *fp=fopen("/proc/meminfo","r");

    if(!fp) return 0.0;

    unsigned long long total=0,avail=0;

    char key[64],unit[32];
    unsigned long long val;

    while(fscanf(fp,"%63s %llu %31s",key,&val,unit)==3)
    {
        if(strcmp(key,"MemTotal:")==0)
            total=val;

        else if(strcmp(key,"MemAvailable:")==0)
            avail=val;

        if(total && avail) break;
    }

    fclose(fp);

    if(total==0) return 0.0;

    return ((double)(total-avail)/total)*100.0;
}

//////////////////////////////////////////////////////////////////
// Disk usage
//////////////////////////////////////////////////////////////////

static double disk_percent(char *path)
{
    struct statvfs v;

    if(statvfs(path,&v)!=0) return 0.0;

    unsigned long long total=(unsigned long long)v.f_blocks*v.f_frsize;
    unsigned long long freeb=(unsigned long long)v.f_bavail*v.f_frsize;

    if(total==0) return 0.0;

    return ((double)(total-freeb)/total)*100.0;
}

//////////////////////////////////////////////////////////////////
// Collector thread
//////////////////////////////////////////////////////////////////

static void *collector_thread(void *arg)
{
    (void)arg;

    while(!stop_flag)
    {
        double c=cpu_percent();

        if(stop_flag) break;

        double m=mem_percent();
        double d=disk_percent(disk_path);

        pthread_mutex_lock(&mtx);

        snap.cpu=c;
        snap.mem=m;
        snap.disk=d;

        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

//////////////////////////////////////////////////////////////////
// Logger thread
//////////////////////////////////////////////////////////////////

static void *logger_thread(void *arg)
{
    (void)arg;

    int fd=open("Marvellous_log.txt",O_CREAT|O_WRONLY|O_APPEND,0666);

    if(fd<0)
    {
        perror("open");
        return NULL;
    }

    char ts[64];
    timestamp(ts,sizeof(ts));

    char sysbuf[512];
    system_info(sysbuf,sizeof(sysbuf));

    char header[1024];

    int hn=snprintf(header,sizeof(header),
    "\n================ Marvellous System Logger ================\n"
    "%s"
    "Log created at: %s\n"
    "Disk path: %s | Interval: %d sec\n"
    "==========================================================\n",
    sysbuf,
    ts,
    disk_path,
    interval_sec);

    write(fd,header,hn);

    while(!stop_flag)
    {
        double c,m,d;

        pthread_mutex_lock(&mtx);

        c=snap.cpu;
        m=snap.mem;
        d=snap.disk;

        pthread_mutex_unlock(&mtx);

        timestamp(ts,sizeof(ts));

        char line[256];

        int n=snprintf(line,sizeof(line),
        "[%s] CPU:%6.2f%% MEM:%6.2f%% DISK(%s):%6.2f%%\n",
        ts,c,m,disk_path,d);

        printf("%s",line);
        write(fd,line,n);

        for(int i=0;i<interval_sec && !stop_flag;i++)
            sleep(1);
    }

    timestamp(ts,sizeof(ts));

    char footer[256];

    int fn=snprintf(footer,sizeof(footer),
    "================ Logger Stopped ================\n"
    "Stopped at: %s\n"
    "================================================\n",
    ts);

    write(fd,footer,fn);

    close(fd);

    return NULL;
}

//////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    if(argc==2)
    {
        disk_path=argv[1];
    }
    else if(argc==3)
    {
        disk_path=argv[1];
        interval_sec=atoi(argv[2]);

        if(interval_sec<=0)
            interval_sec=2;
    }

    printf("Marvellous System Logger\n\n");

    char sysbuf[512];
    system_info(sysbuf,sizeof(sysbuf));

    printf("%s",sysbuf);

    printf("Path : %s\n",disk_path);
    printf("Interval : %d sec\n",interval_sec);
    printf("Press Ctrl+C to stop...\n");

    struct sigaction sa;

    memset(&sa,0,sizeof(sa));

    sa.sa_handler=sigint_handler;

    sigaction(SIGINT,&sa,NULL);

    pthread_t t_collect,t_log;

    if(pthread_create(&t_collect,NULL,collector_thread,NULL)!=0)
    {
        perror("pthread_create");
        return 1;
    }

    if(pthread_create(&t_log,NULL,logger_thread,NULL)!=0)
    {
        perror("pthread_create");
        stop_flag=1;

        pthread_join(t_collect,NULL);

        return 1;
    }

    pthread_join(t_collect,NULL);
    pthread_join(t_log,NULL);

    printf("\nTerminating Marvellous System Logger\n");
    printf("Log saved in Marvellous_log.txt\n");

    return 0;
}