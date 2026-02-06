#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int, int) = NULL;
    int choice = 0;
    int a = 0, b = 0;
    int result = 0;
    char *error = NULL;

    /* Load shared library */
    handle = dlopen("./LIBClient.so", RTLD_NOW);
    if (handle == NULL)
    {
        printf("Unable to load library: %s\n", dlerror());
        return -1;
    }

    printf("Library loaded successfully\n");

    /* Take input from user */
    printf("\nEnter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("\nSelect Operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Clear any old errors */
    dlerror();

    /* Select function based on choice */
    switch (choice)
    {
        case 1:
            *(void **)(&fp) = dlsym(handle, "Addition");
            break;

        case 2:
            *(void **)(&fp) = dlsym(handle, "Subtraction");
            break;

        case 3:
            *(void **)(&fp) = dlsym(handle, "Multiplication");
            break;

        case 4:
            *(void **)(&fp) = dlsym(handle, "Division");
            break;

        default:
            printf("Invalid choice\n");
            dlclose(handle);
            return -1;
    }

    /* Check dlsym error */
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading function: %s\n", error);
        dlclose(handle);
        return -1;
    }

    /* Call function */
    result = fp(a, b);
    printf("Result is: %d\n", result);

    /* Close library */
    dlclose(handle);
    return 0;
}
