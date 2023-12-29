#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
