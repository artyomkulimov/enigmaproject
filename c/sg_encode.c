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

    int n = 1000;  // max lenght of the sequence
    char* message = calloc(n, sizeof(char));

    printf("Input message: ");
    fgets(message, n, stdin);
    message = fgets(message, n, stdin);
    message[strcspn(message, "\n")] = '\0';
    n = strlen(message);

    char* encMessage = calloc(n, sizeof(char));

    // message encoding
    for (i = 55; i < n + 55; i++) {
        x = xs[31] - xs[0];
        for (int j = 0; j < 54; j++) {
            xs[j] = xs[j + 1];
        }
        xs[54] = x;
        encMessage[i - 55] = (message[i - 55] ^ x);
        // printf("%d ",x);
    }


    printf("\n");
    printf("Encoded message size: %d\n", n);

    printf("\n");
    printf("Encoded message numerical:\n");
    for (i = 0; i < n; i++) {
        printf("%hhu ", encMessage[i]);
    }

    return 0;
}
