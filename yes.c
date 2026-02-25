#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *msg = "y"; // default

    if (argc > 1) msg = argv[1]; // если передали что-то, выводим это

    while (1) {
        printf("%s\n", msg);
    }

    return 0;
}