#include <stdio.h>
#include <stdlib.h>

uint32_t* getRandomMessage(int n) {
    srand(300);
    uint32_t* mes = calloc(n, sizeof(uint32_t));
    for (int i = 0; i < n; i++) {
        mes[i] = rand() % 2;
    }
    return mes;
}

int main(void) {
    uint32_t* keys = calloc(55, sizeof(uint32_t));
    uint32_t* xs = calloc(55, sizeof(uint32_t));
    uint32_t x, r;
    int i;

    int n = 60;  // lenght of the sequence
    uint32_t* message = getRandomMessage(n);
    uint32_t* encMessage = calloc(n, sizeof(uint32_t));
    uint32_t* decMessage = calloc(n, sizeof(uint32_t));

    srand(420);
    for (i = 0; i < 55; i++) {
        keys[i] = rand();
        xs[i] = keys[i];
    }

    // message encoding
    for (i = 55; i < n + 55; i++) {
        x = xs[(i - 24) % 55] - xs[(i - 55) % 55];
        for (int j = 0; j < 54; j++) {
            xs[j] = xs[j + 1];
        }
        xs[54] = x;
        r = (x > RAND_MAX);
        encMessage[i - 55] = (message[i - 55] ^ r);
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
        r = (x > RAND_MAX);
        decMessage[i - 55] = (encMessage[i - 55] ^ r);
    }

    printf("Original message: ");
    for (i = 0; i < n; i++) {
        printf("%d ", message[i]);
    }

    printf("\n");

    printf("Encoded message:  ");
    for (i = 0; i < n; i++) {
        printf("%d ", encMessage[i]);
    }

    printf("\n");

    printf("Decoded message:  ");
    for (i = 0; i < n; i++) {
        printf("%d ", decMessage[i]);
    }

    return 0;
}