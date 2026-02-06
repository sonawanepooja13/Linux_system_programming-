/* 
Display file complete information 
accept a filename and display file metadata using stat()
size, indode ,hardlink,permisssion,owner, uid,gid,file type.last access, modified date

*/
       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/stat.h>
       #include<time.h>

       int main()
       {


        char filename[100]; 
        struct stat sobj; 
        int fd=0; 

        printf("enter which file you wamt to open :");
        scanf("%s",filename);

        fd=stat(filename,&sobj); 
        if(fd==-1)
        {
            perror(filename); 

        }   
        printf("File information"); 
        printf("Inode number : %ld\n",sobj.st_ino); //inode number 
        printf("Size of file : %ld\n",sobj.st_size);//size 
        printf("Size of block: %ld\n",sobj.st_blksize);//block   size 
        printf("Hardlink Size : %ld\n",sobj.st_nlink);
        printf("Ownwer :%u\n",sobj.st_uid); 
        printf("Group ID :%u\n",sobj.st_gid); 

        printf("File Permission  \n" ); 
        printf("Permissions       : %o\n", sobj.st_mode & 0777);
        
    /* File type */
    printf("File Type         : ");
    if (S_ISREG(sobj.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(sobj.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(sobj.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(sobj.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISLNK(sobj.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(sobj.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    printf("Last Access Time  : %s", ctime(&sobj.st_atime));
    printf("Last Modify Time  : %s", ctime(&sobj.st_mtime));
    printf("Last Status Change: %s", ctime(&sobj.st_ctime));

    return 0;
}

