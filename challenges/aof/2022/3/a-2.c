#include <glib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int getPriority(char ch) {
    int code = ch;
    if (code >= 97) {
        return code - 96;
    } else {
        return code - 38;
    }
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Failed opening file.");
        return 1;
    }

    int prioSum = 0;
    char string[100];
    int counter = 0;
    char stringConcat[256];
    int lenArr[3];

    while (fgets(string, 100, fp)) {
        lenArr[counter] = strlen(string);

        counter++;
        if (counter < 2) {
            strcat(stringConcat, string);
            continue;
        }

        strcat(stringConcat, string);

        size_t length = strlen(stringConcat) - 1;
        GHashTable *firstCharSet = g_hash_table_new(NULL, NULL);
        GHashTable *secondCharSet = g_hash_table_new(NULL, NULL);

        for (size_t i = 0; i < length; i++) {
            char ch = stringConcat[i];

            if (i < lenArr[0]) {
                gboolean added = g_hash_table_insert(
                    firstCharSet, GINT_TO_POINTER(ch), GINT_TO_POINTER(ch));
            } else if (i >= lenArr[0] && i < lenArr[1]) {
                gpointer value =
                    g_hash_table_lookup(firstCharSet, GINT_TO_POINTER(ch));

                if (value != NULL) {
                    gboolean added =
                        g_hash_table_insert(secondCharSet, GINT_TO_POINTER(ch),
                                            GINT_TO_POINTER(ch));
                }
            } else if (i >= lenArr[1]) {
                gpointer value =
                    g_hash_table_lookup(secondCharSet, GINT_TO_POINTER(ch));

                if (value != NULL) {
                    int val = (char)GPOINTER_TO_INT(value);
                    prioSum += getPriority(val);
                    break;
                }
            }
        }

        g_hash_table_destroy(firstCharSet);
        g_hash_table_destroy(secondCharSet);
        memset(stringConcat, 0, sizeof(stringConcat));
    }

    fclose(fp);

    printf("%d", prioSum);

    return 0;
}

