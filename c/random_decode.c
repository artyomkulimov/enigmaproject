#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    uint8_t seed, x;

    printf("Input seed: ");
    scanf("%hhu", &seed);

    int n;  // lenght of the sequence
    printf("Input encoded size: ");
    scanf("%d", &n);

    char* encMessage = calloc(n, sizeof(char));
    printf("Input encoded message numerical: ");
    for (i = 0; i < n; i++) {
        scanf("%hhu", &encMessage[i]);
    }

    char* decMessage = calloc(n + 1, sizeof(char)); // reserve an extra byte for the end of the string marker(\0)

    // message decoding
    srand(seed);
    for (i = 0; i < n; i++) {
        x = rand() % 256;
        decMessage[i] = (encMessage[i] ^ x);
    }

    printf("Decoded message:\n%s\n", decMessage);

    return 0;
}
