#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // only for testing performance
    clock_t start = clock();

    FILE *fp = fopen("sample.txt", "r");
    // FILE *fp = fopen("input.txt", "r");

    char *content = NULL;
    char line[1000];
    size_t content_size = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        size_t line_length = strlen(line);
        content = realloc(content, content_size + line_length + 1);
        if (content == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            return 1;
        }
        strcpy(content + content_size, line);
        content_size += line_length;
    }

    fclose(file);

    printf("File content:\n%s", content);

    // only for testing performance
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds);

    return 0;
}

