#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i;
    uint8_t a;
    uint8_t c;
    uint8_t x;
    uint8_t seed;

    printf("Input seed: ");
    scanf("%hhu", &seed);

    printf("Input a: ");
    scanf("%hhu", &a);

    printf("Input c: ");
    scanf("%hhu", &c);

    int n = 1000;  // max lenght of the sequence
    char* message = calloc(n, sizeof(char));

    printf("Input message: ");
    message = fgets(message, n, stdin);
    message[strcspn(message, "\n")] = '\0';
    n = strlen(message);

    char* encMessage = calloc(n, sizeof(char));
    char* decMessage = calloc(n, sizeof(char));

    // message encoding
    x = seed;
    for (int i = 0; i < n; i++) {
        x = a * x + c;
        encMessage[i] = (message[i] ^ x);
    }

    // message decoding
    x = seed;
    for (i = 0; i < n; i++) {
        x = a * x + c;
        decMessage[i] = (encMessage[i] ^ x);
    }

    printf("Original message: %s\n", message);

    printf("Encoded message: %s\n", encMessage);

    printf("Decoded message: %s\n", decMessage);

    return 0;
}