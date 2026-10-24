#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    int method, a, c, n, size, value;
    unsigned char encrypted[1000];
    unsigned char decoded[1000];
    unsigned char known[1000];

    printf("Input method (1 = rand, 2 = lcg), a and c (use 0 0 for rand): ");
    if (scanf("%d %d %d", &method, &a, &c) != 3) return 1;
    if (method < 1 || method > 2 || a < 0 || a > 255 || c < 0 || c > 255) return 1;
    printf("Input encoded size: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 999) return 1;

    // encoded message input
    printf("Input encoded message numerical: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1 || value < 0 || value > 255) return 1;
        encrypted[i] = value;
    }

    // known part of the message
    printf("Input known message size: ");
    if (scanf("%d", &size) != 1 || size < 1 || size > n) return 1;
    printf("Input known message numerical: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &value) != 1 || value < 0 || value > 255) return 1;
        known[i] = value;
    }

    // try every seed
    printf("\nMatching seeds and decoded message bytes:\n");
    clock_t start = clock();
    for (int seed = 0; seed <= 255; seed++) {
        uint8_t x = seed;
        srand(seed);

        // message decoding
        for (int i = 0; i < n; i++) {
            if (method == 1) {
                x = rand() % 256;
            } else {
                x = a * x + c;
            }
            decoded[i] = encrypted[i] ^ x;
        }

        // check for a match
        for (int i = 0; i <= n - size; i++) {
            if (memcmp(decoded + i, known, size) == 0) {
                printf("%d", seed);
                for (int j = 0; j < n; j++) {
                    printf(" %u", (unsigned int)decoded[j]);
                }
                printf("\n");
                break;
            }
        }
    }

    double seconds = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("CPU time for 256 seeds: %.6f seconds\n", seconds);

    return 0;
}
