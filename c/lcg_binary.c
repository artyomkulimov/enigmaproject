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
    uint32_t seed = 21403;
    uint32_t a = 5;
    uint32_t c = 3;
    uint32_t x, r;
    int i;

    int n = 60;  // lenght of the sequence
    uint32_t* message = getRandomMessage(n);
    uint32_t* encMessage = calloc(n, sizeof(uint32_t));
    uint32_t* decMessage = calloc(n, sizeof(uint32_t));

    // message encoding
    x = seed;
    for (int i = 0; i < n; i++) {
        x = a * x + c;
        r = (x > RAND_MAX);
        encMessage[i] = (message[i] ^ r);
    }

    // message decoding
    x = seed;
    for (i = 0; i < n; i++) {
        x = a * x + c;
        r = (x > RAND_MAX);
        decMessage[i] = (encMessage[i] ^ r);
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