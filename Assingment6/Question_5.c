#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle_lazy = NULL;
    void *handle_now = NULL;
    int (*fp)(int, int);
    char *error;

    printf("Loading library using RTLD_LAZY...\n");
    handle_lazy = dlopen("./LIBClient.so", RTLD_LAZY);
    if (handle_lazy == NULL)
    {
        printf("RTLD_LAZY dlopen failed: %s\n", dlerror());
    }
    else
    {
        printf("RTLD_LAZY dlopen succeeded\n");
    }

    printf("\nLoading library using RTLD_NOW...\n");
    handle_now = dlopen("./LIBClient.so", RTLD_NOW);
    if (handle_now == NULL)
    {
        printf("RTLD_NOW dlopen failed: %s\n", dlerror());
    }
    else
    {
        printf("RTLD_NOW dlopen succeeded\n");
    }

    /* Try loading invalid symbol using RTLD_LAZY */
    printf("\nTrying to load invalid symbol using RTLD_LAZY handle...\n");
    dlerror();  // clear old error
    fp = (int (*)(int,int)) dlsym(handle_lazy, "InvalidFunction");
    error = dlerror();
    if (error != NULL)
    {
        printf("RTLD_LAZY: Symbol not found (but dlopen succeeded earlier)\n");
    }

    /* Try loading invalid symbol using RTLD_NOW */
    printf("\nTrying to load invalid symbol using RTLD_NOW handle...\n");
    dlerror();  // clear old error
    fp = (int (*)(int,int)) dlsym(handle_now, "InvalidFunction");
    error = dlerror();
    if (error != NULL)
    {
        printf("RTLD_NOW: Symbol not found\n");
    }

    dlclose(handle_lazy);
    dlclose(handle_now);

    return 0;
}
