#include <stdio.h>

void hello();   // Function from shared library

int main() {
    hello();
    return 0;
}
