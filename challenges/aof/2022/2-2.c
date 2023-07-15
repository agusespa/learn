#include <stdio.h>

int main(void) {
    FILE *fp;
    fp = fopen("input2.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 0;
    }

    char str[5];
    int totalScore = 0;
    int roundScore = 0;

    while (fgets(str, sizeof(str), fp) != NULL) {
        if (str[0] == 'A') {
            if (str[2] == 'X') {
                roundScore = 0 + 3;
            } else if (str[2] == 'Y') {
                roundScore = 3 + 1;
            } else if (str[2] == 'Z') {
                roundScore = 6 + 2;
            }
        } else if (str[0] == 'B') {
            if (str[2] == 'X') {
                roundScore = 0 + 1;
            } else if (str[2] == 'Y') {
                roundScore = 3 + 2;
            } else if (str[2] == 'Z') {
                roundScore = 6 + 3;
            }
        } else if (str[0] == 'C') {
            if (str[2] == 'X') {
                roundScore = 0 + 2;
            } else if (str[2] == 'Y') {
                roundScore = 3 + 3;
            } else if (str[2] == 'Z') {
                roundScore = 6 + 1;
            }
        }

        totalScore += roundScore;
    }

    fclose(fp);

    printf("%d", totalScore);

    return 0;
}

