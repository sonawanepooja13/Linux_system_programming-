

//  argc = 1
//  argv[0]
// ./myexe

//  argc = 2
//  argv[0]  argv[1]
// ./myexe  /home/Demo

//  argc = 3
//  argv[0]  argv[1]    argv[2]
// ./myexe  /home/Demo  5

//////////////////////////////////////////////////////////////////
//
//	Header file inclusion
//
//////////////////////////////////////////////////////////////////

#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/statvfs.h>

//////////////////////////////////////////////////////////////////
//
//	Global variable creation
//
//////////////////////////////////////////////////////////////////

static volatile sig_atomic_t stop_flag = 0;

// ctrl+c handler
static void sigint_handler(int sig)
{
	(void)sig;
	
	printf("Marvellous System Logger is terminating...\n");
	
	// Tell the threads to stop the execution
	stop_flag = 1;
}

// structure which holds all system information
typedef struct
{
	double cpu;	// CPU usage percentage
	double mem;	// RAM usage percentage
	double disk;	// Harddisk usage percentage
}Snapshot;

// Global object which holds information
static Snapshot snap;

// Mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Default path for disk 
static const char * disk_path = "/";

// Sleep timer for log
static int interval_sec = 2;

//////////////////////////////////////////////////////////////////
//
//	Helper functions definations
//
//////////////////////////////////////////////////////////////////

// Thread proc for thread which collects system information
static void * collector_thread(void *arg)
{
	(void)arg;
	
	printf("Inside collector thread\n");
	
	return NULL;
}

// Thread proc for thread which writes log
static void * logger_thread(void *arg)
{
	(void)arg;
	
	printf("Inside logger thread\n");
	
	return NULL;
}

//////////////////////////////////////////////////////////////////
//
//	Entry point function of project
//
//////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	// ./myexe  /home/Demo
	if(argc == 2)
	{
		disk_path = argv[1];
	}
	// ./myexe  /home/Demo  5
	else if(argc == 3)
	{
		disk_path = argv[1];
		interval_sec = atoi(argv[2]);
	}
	
	printf("Marvellous System Logger\n");
	
	printf("Path is : %s\n",disk_path);
	printf("Interval is : %d\n",interval_sec);
	
	
	// Structure for handling ctrl+c
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	
	sa.sa_handler = sigint_handler;
	
	sigaction(SIGINT,&sa,NULL);

	// Thread to collect the information
	pthread_t t_collect;
	
	// Thread to write the data into log
	pthread_t t_log;
	
	// Create thread to collect information
	pthread_create(&t_collect,NULL,collector_thread,NULL);
	
	// Create thread to write data into log
	pthread_create(&t_log,NULL,logger_thread,NULL);
	
	// Main thread Waiting for child threads to terminate
	pthread_join(t_collect,NULL);
	pthread_join(t_log,NULL);
	
	printf("Terminating the Marvellous System Logger\n");
	
	return 0;
}

