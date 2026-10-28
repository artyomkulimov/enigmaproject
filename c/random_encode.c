#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    uint8_t seed, x; // generator's variables

    // reading the input
    printf("Input seed: ");
    scanf("%hhu", &seed);

    int n = 1000;  // max lenght of the sequence
    char* message = calloc(n, sizeof(char));

    fgets(message, n, stdin);
    printf("Input message: ");
    message = fgets(message, n, stdin);
    message[strcspn(message, "\n")] = '\0';
    n = strlen(message);

    char* encMessage = calloc(n, sizeof(char));

    // message encoding
    srand(seed);
    for (int i = 0; i < n; i++) {
        // generating a new byte
        x = rand() % 256;
        encMessage[i] = (message[i] ^ x);
    }

    printf("Encoded message size: %d\n", n);
    printf("Encoded message bytes:\n");
    for (i = 0; i < n; i++) {
        printf("%hhu ", encMessage[i]);
    }

    return 0;
}
