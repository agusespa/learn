#include <stdio.h>

int main(void) {
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 1;
    }


    fclose(fp);

    printf("%d", 1);

    return 0;
}

