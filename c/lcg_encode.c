#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i;
    // generator's variables
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

    fgets(message, n, stdin);
    printf("Input message: ");
    message = fgets(message, n, stdin);
    message[strcspn(message, "\n")] = '\0';
    n = strlen(message);

    char* encMessage = calloc(n, sizeof(char));

    // message encoding
    x = seed;
    for (int i = 0; i < n; i++) {
        // generating a new byte
        x = a * x + c;
        encMessage[i] = (message[i] ^ x);
    }

    printf("Encoded message size: %d\n", n);
    printf("Encoded message bytes:\n");
    for (i = 0; i < n; i++) {
        printf("%hhu ", encMessage[i]);
    }

    return 0;
}
