#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char* programs[] = {
        "random_encode", "random_decode",
        "lcg_encode", "lcg_decode",
        "sg_encode", "sg_decode",
        "brute_force"
    };
    int choice;
    char input[100], extra;
    char command[512];

    setvbuf(stdin, NULL, _IONBF, 0);

    printf("ENIGMA++\n");
    printf("1. random encode\n2. random decode\n");
    printf("3. lcg encode\n4. lcg decode\n");
    printf("5. sg encode\n6. sg decode\n");
    printf("7. brute force\n");
    printf("Choose an option: ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) return 1;
    if (sscanf(input, "%d %c", &choice, &extra) != 1 || choice < 1 || choice > 7) {
        printf("Invalid option.\n");
        return 1;
    }

    const char* name = programs[choice - 1];
    snprintf(command, sizeof(command),
        "mkdir -p build && cc -std=c11 -Wall -Wextra -pedantic c/%s.c -o build/%s && ./build/%s",
        name, name, name);

    if (system(command) != 0) {
        printf("Could not compile or run the program. Run this menu from the project folder.\n");
        return 1;
    }

    return 0;
}
