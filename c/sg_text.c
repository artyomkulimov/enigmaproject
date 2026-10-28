#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i;
    uint8_t* keys = calloc(55, sizeof(uint8_t));
    uint8_t* xs = calloc(55, sizeof(uint8_t));
    uint8_t x, r;

    printf("Input 55 keys: ");
    for (i = 0; i < 55; i++) {
        scanf("%hhu", &keys[i]);
        xs[i] = keys[i];
    }

    int n = 1000;  // max lenght of the sequence
    char* message = calloc(n, sizeof(char));

    printf("Input message: ");
    message = fgets(message, n, stdin);
    message[strcspn(message, "\n")] = '\0';
    n = strlen(message);

    char* encMessage = calloc(n, sizeof(char));
    char* decMessage = calloc(n, sizeof(char));

    // message encoding
    for (i = 55; i < n + 55; i++) {
        x = (xs[(i - 24) % 55] - xs[(i - 55) % 55]);
        for (int j = 0; j < 54; j++) {
            xs[j] = xs[j + 1];
        }
        xs[54] = x;
        encMessage[i - 55] = (message[i - 55] ^ x);
        // printf("%d ",x);
    }

    // message decoding
    for (i = 0; i < 55; i++) {
        xs[i] = keys[i];
    }
    for (i = 55; i < n + 55; i++) {
        x = xs[(i - 24) % 55] - xs[(i - 55) % 55];
        for (int j = 0; j < 54; j++) {
            xs[j] = xs[j + 1];
        }
        xs[54] = x;
        decMessage[i - 55] = (encMessage[i - 55] ^ x);
    }

    printf("Original message: %s\n", message);

    printf("Encoded message: %s\n", encMessage);

    printf("Decoded message: %s\n", decMessage);

    return 0;
}