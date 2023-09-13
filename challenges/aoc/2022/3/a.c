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

    while (fgets(string, 100, fp)) {
        size_t length = strlen(string) - 1;
        GHashTable *charSet = g_hash_table_new(NULL, NULL);

        for (size_t i = 0; i < length; i++) {
            char ch = string[i];

            if (i >= length / 2) {
                gpointer value =
                    g_hash_table_lookup(charSet, GINT_TO_POINTER(ch));

                if (value != NULL) {
                    int val = (char)GPOINTER_TO_INT(value);
                    prioSum += getPriority(val);
                    break;
                }
            } else {
                gboolean added = g_hash_table_insert(
                    charSet, GINT_TO_POINTER(ch), GINT_TO_POINTER(ch));
            }
        }

        g_hash_table_destroy(charSet);
    }

    fclose(fp);

    printf("%d", prioSum);

    return 0;
}

