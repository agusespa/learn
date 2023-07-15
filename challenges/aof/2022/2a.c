#include <stdio.h>
#include <time.h>

int main(void) {
    FILE *fp = fopen("input2.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 1;
    }

    // only for testing performance
    clock_t start = clock();

    char str[5];
    int totalScore = 0;
    int roundScore = 0;

    // only for testing performance
    for (int i = 0; i < 100000000; i++) {

        while (fgets(str, sizeof(str), fp) != NULL) {
            if (str[0] == 'A') {
                if (str[2] == 'X') {
                    roundScore = 3;
                } else if (str[2] == 'Y') {
                    roundScore = 6;
                } else if (str[2] == 'Z') {
                    roundScore = 0;
                }
            } else if (str[0] == 'B') {
                if (str[2] == 'X') {
                    roundScore = 0;
                } else if (str[2] == 'Y') {
                    roundScore = 3;
                } else if (str[2] == 'Z') {
                    roundScore = 6;
                }
            } else if (str[0] == 'C') {
                if (str[2] == 'X') {
                    roundScore = 6;
                } else if (str[2] == 'Y') {
                    roundScore = 0;
                } else if (str[2] == 'Z') {
                    roundScore = 3;
                }
            }

            if (str[2] == 'X') {
                roundScore += 1;
            } else if (str[2] == 'Y') {
                roundScore += 2;
            } else if (str[2] == 'Z') {
                roundScore += 3;
            }

            totalScore += roundScore;
        }
    }

    // only for testing performance
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds); // 2.197 sec

    fclose(fp);

    printf("%d", totalScore);

    return 0;
}

