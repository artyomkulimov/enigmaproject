#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    uint8_t seed, x;

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
        x = rand() % 256;
        encMessage[i] = (message[i] ^ x);
    }

    printf("\n");
    printf("Encoded message:\n%s\n", encMessage);

    printf("\n");
    printf("Encoded message size: %d\n", n);

    printf("\n");
    printf("Encoded message numerical:\n");
    for (i = 0; i < n; i++) {
        printf("%hhu ", encMessage[i]);
    }

    return 0;
}