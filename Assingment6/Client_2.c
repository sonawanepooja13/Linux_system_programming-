#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0;
    int (*fp)(int, int);
    char *error;

    /* Load shared library */
    handle = dlopen("./libClient2.so", RTLD_LAZY);
    if (!handle)
    {
        printf("Unable to load library: %s\n", dlerror());
        return -1;
    }

    printf("Library loaded successfully\n");

    /* Clear any existing error */
    dlerror();

    /* Get Addition function */
    fp = (int (*)(int, int))dlsym(handle, "Addition");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Addition(): %s\n", error);
        dlclose(handle);
        return -1;
    }

    iRet = fp(11, 10);
    printf("Addition is: %d\n", iRet);

    /* Clear error again */
    dlerror();

    /* Get Substraction function */
    fp = (int (*)(int, int))dlsym(handle, "Substraction");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Substraction(): %s\n", error);
        dlclose(handle);
        return -1;
    }

    iRet = fp(11, 10);
    printf("Substraction is: %d\n", iRet);

    /* Close library */
    dlclose(handle);
    return 0;
}
