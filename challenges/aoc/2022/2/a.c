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
    int score = 0;

    // only for testing performance
    for (int i = 0; i < 100000000; i++) {

        while (fgets(str, sizeof(str), fp) != NULL) {
            if (str[0] == 'A') {
                if (str[2] == 'X') {
                    score += 3 + 1;
                } else if (str[2] == 'Y') {
                    score += 6 + 2;
                } else if (str[2] == 'Z') {
                    score += 0 + 3;
                }
            } else if (str[0] == 'B') {
                if (str[2] == 'X') {
                    score += 0 + 1;
                } else if (str[2] == 'Y') {
                    score += 3 + 2;
                } else if (str[2] == 'Z') {
                    score += 6 + 3;
                }
            } else if (str[0] == 'C') {
                if (str[2] == 'X') {
                    score += 6 + 1;
                } else if (str[2] == 'Y') {
                    score += 0 + 2;
                } else if (str[2] == 'Z') {
                    score += 3 + 3;
                }
            }
        }
    }

    // only for testing performance
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds); // 4.876 sec on 2016 MacBook

    fclose(fp);

    printf("%d\n", score);

    return 0;
}

