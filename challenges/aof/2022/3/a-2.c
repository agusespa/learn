#include <glib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int getPriority(int ch) {
    if (ch >= 97) {
        return ch - 96;
    } else {
        return ch - 38;
    }
}

int main(void) {
    // only for testing performance
    clock_t start = clock();

    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 1;
    }

    int prioSum = 0;
    char string[100];
    int counter = 0;
    char strings[3][100];

    while (fgets(string, 100, fp)) {
        if (counter < 2) {
            strcpy(strings[counter], string);
            counter++;
            continue;
        }

        strcpy(strings[counter], string);

        GHashTable *charMap = g_hash_table_new(NULL, NULL);

        for (int i = 0; i < 3; i++) {
            int length = strlen(strings[i]);

            for (int j = 0; j < length - 1; j++) {
                char ch = strings[i][j];

                if (i == 0) {
                    gboolean added = g_hash_table_insert(
                        charMap, GINT_TO_POINTER(ch), GINT_TO_POINTER(1));
                } else if (i == 1) {
                    gpointer value =
                        g_hash_table_lookup(charMap, GINT_TO_POINTER(ch));

                    if (value != NULL) {
                        gboolean added = g_hash_table_insert(
                            charMap, GINT_TO_POINTER(ch), GINT_TO_POINTER(2));
                    }
                } else if (i == 2) {
                    gpointer value =
                        g_hash_table_lookup(charMap, GINT_TO_POINTER(ch));

                    if (value != NULL) {
                        int intValue = GPOINTER_TO_INT(value);
                        if (intValue == 2) {
                            prioSum += getPriority(ch);
                            break;
                        }
                    }
                }
            }
        }

        g_hash_table_destroy(charMap);
        counter = 0;
    }

    fclose(fp);

    printf("%d", prioSum);

    // only for testing performance
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds); // 0.0007 sec on 2016 MacBook

    return 0;
}

