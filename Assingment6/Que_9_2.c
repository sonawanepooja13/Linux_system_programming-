// main.c
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

// Function pointer type
typedef int (*func_ptr)(int, int);

int main() {
    void *handle;
    char *error;

    // Load shared library
    handle = dlopen("LIBClient_9.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    dlerror(); // Clear any existing error

    // Array of function pointers
    func_ptr functions[3];

    // Load functions dynamically
    functions[0] = (func_ptr)dlsym(handle, "add");
    functions[1] = (func_ptr)dlsym(handle, "sub");
    functions[2] = (func_ptr)dlsym(handle, "mul");

    // Check for errors
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    int a = 10, b = 5;

    // Invoke functions and display addresses & results
    for (int i = 0; i < 3; i++) {
        printf("Function %d address: %p, Result: %d\n",
               i + 1,
               (void *)functions[i],
               functions[i](a, b));
    }

    // Close the library
    dlclose(handle);
    return 0;
}
