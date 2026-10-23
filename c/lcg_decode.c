#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
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
    x = seed;
    for (i = 0; i < n; i++) {
        x = a * x + c;
        decMessage[i] = (encMessage[i] ^ x);
    }

    printf("Decoded message:\n%s\n", decMessage);

    return 0;
}