/*Design and implement a mini dynamic library inspection tool.
The program should:
• Accept shared library path and symbol name as command-line arguments
• Load the library using dlopen()
• Check whether the given symbol exists using dlsym()
• Display symbol address if found
• Display appropriate error message otherwise*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>


int main(int argc, char *argv[])
{
     void *handle; 
     void *error; 
     void *symbol; 

     // check a comamnd liine 
     if(argc!=3)
     {
        printf("Usuage :%s <shared_library_path><symbol_name>\n",argv[0]); 
        return 1; 
     }
     handle=dlopen(argv[1],RTLD_LAZY); 
     if(!handle)
     {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1; 
     }

     //clear an existing error 
     dlerror(); 
     //look for symbol 
     symbol=dlsym(handle,argv[2]);
     error=dlerror(); 

     if(error!=NULL)
     {
        printf("SYmbol %s not found in library\n",argv[2]); 

     }
     else
     {
        printf("Symbol %s found ddress :%p\n",argv[2],symbol); 

     }
     //close library 
     dlclose(handle); 
     return 0; 
}