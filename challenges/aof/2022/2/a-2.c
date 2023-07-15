#include <stdio.h>

int main(void) {
    FILE *fp;
    fp = fopen("input2.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 1;
    }

    char str[5];
    int score = 0;

    while (fgets(str, sizeof(str), fp) != NULL) {
        if (str[0] == 'A') {
            if (str[2] == 'X') {
                score += 0 + 3;
            } else if (str[2] == 'Y') {
                score += 3 + 1;
            } else if (str[2] == 'Z') {
                score += 6 + 2;
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
                score += 0 + 2;
            } else if (str[2] == 'Y') {
                score += 3 + 3;
            } else if (str[2] == 'Z') {
                score += 6 + 1;
            }
        }
    }

    fclose(fp);

    printf("%d\n", score);

    return 0;
}

