#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    void (*func)();
    char *error;

    /* Clear any existing error */
    dlerror();

    /* 1. Load a valid shared library */
    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("Error loading library: %s\n", dlerror());
        return 1;
    }
    printf("Shared library loaded successfully.\n");

    /* 2. Get a VALID function */
    func = (void (*)()) dlsym(handle, "hello");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error finding symbol 'hello': %s\n", error);
    }
    else
    {
        printf("Calling valid function:\n");
        func();
    }

    /* 3. Get an INVALID function */
    func = (void (*)()) dlsym(handle, "invalid_function");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error finding symbol 'invalid_function': %s\n", error);
    }

    /* Close library */
    dlclose(handle);

    return 0;
}
