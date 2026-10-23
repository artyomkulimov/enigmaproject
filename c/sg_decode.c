#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    uint8_t* keys = calloc(55, sizeof(uint8_t));
    uint8_t* xs = calloc(55, sizeof(uint8_t));
    uint8_t x, r;

    printf("Input 55 keys: ");
    for (i = 0; i < 55; i++) {
        scanf("%hhu", &keys[i]);
        xs[i] = keys[i];
    }

    int n;  // lenght of the sequence
    printf("Input encoded size: ");
    scanf("%d", &n);

    char* encMessage = calloc(n, sizeof(char));
    printf("Input encoded message numerical: ");
    for (i = 0; i < n; i++) {
        scanf("%hhu", &encMessage[i]);
    }

    char* decMessage = calloc(n, sizeof(char));

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

    printf("Decoded message: %s\n", decMessage);

    return 0;
}