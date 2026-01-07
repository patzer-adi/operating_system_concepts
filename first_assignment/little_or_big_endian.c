#include <stdio.h>

int main() {
    int x = 1;
    char *p = (char *)&x;
    printf("%s\n", *p ? "Little Endian" : "Big Endian");
}
