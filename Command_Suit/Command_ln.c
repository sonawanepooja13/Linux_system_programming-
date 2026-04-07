/*
lnx sourcefile.txt   linkfile.txt
start 
create a filename accept source file name and link name file 
check source name exit  exit 
if file exit create a symbolic link 
then create a hardlink 

argv[0] argv[1]  argv[2]   argv[3]
lnx      -s     file1.txt   file2.txt 

*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int iRet=0; 

    //to check argument 
    if(argc<3)
    {
        printf("Usage:\n"); 
        printf("./lnx Source Target  (Hard Link)\n"); 
        printf("./lnx Source Target (Soft Link)\n"); 
        return -1; 
    }

    //startting check -s symbolic link 
    // jar 4 arument asel tr link create kara 
    if(strcmp(argv[1],"-s")==0)
    {
        if(argc!=4)
        {
            printf("Invalid argument\n"); 
            return -1; 
        }
        //create a  symbolic link 
        iRet=symlink(argv[2],argv[3]);
        if(iRet==0)
        {
            printf("Hard link created succesfully\n");
        }
        else
        {
          perror("Link"); 
        }
        return 0; 
    }
}