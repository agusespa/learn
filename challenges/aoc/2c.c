#include <stdio.h>
#include <glib.h>
#include <time.h>

int getShape(char shape) {
    switch (shape) {
        case 'A':
        case 'X':
            return 1; // Rock
        case 'B':
        case 'Y':
            return 2; // Paper
        case 'C':
        case 'Z':
            return 3; // Scissors
        default:
            printf("Invalid shape: %c\n", shape);
            return -1; // Invalid shape
    }
}

int main() {
    char opponent[4];
    char response[4];

    // Open the input file
    FILE *file = fopen("input2.txt", "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Create a hash table
    GHashTable *table = g_hash_table_new(NULL, NULL);

    // Populate the hash table with opponent-response mappings
    g_hash_table_insert(table, "A", "Y");
    g_hash_table_insert(table, "B", "X");
    g_hash_table_insert(table, "C", "Z");

    int totalScore = 0;

    // Start the clock
    clock_t start = clock();

    while (fscanf(file, "%s", opponent) != EOF) {
        // Retrieve the response from the hash table
        char *response = g_hash_table_lookup(table, opponent);

        if (response == NULL) {
            printf("Invalid opponent shape: %s\n", opponent);
            g_hash_table_destroy(table);
            fclose(file);
            return 1;
        }

        int opponentShape = getShape(opponent[0]);
        int responseShape = getShape(response[0]);

        // Invalid shape detected
        if (opponentShape == -1 || responseShape == -1) {
            g_hash_table_destroy(table);
            fclose(file);
            return 1;
        }

        // Calculate the score for the round
        int score;
        if (opponentShape == responseShape) {
            score = 3; // Draw
        } else if ((opponentShape == 1 && responseShape == 3) ||
                   (opponentShape == 2 && responseShape == 1) ||
                   (opponentShape == 3 && responseShape == 2)) {
            score = 0; // Loss
        } else {
            score = 6; // Win
        }

        // Add the round score to the total score
        totalScore += score + responseShape;
    }

    // Destroy the hash table
    g_hash_table_destroy(table);

    // Close the file
    fclose(file);

    // Calculate the elapsed time
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the total score and elapsed time
    printf("Total Score: %d\n", totalScore);
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds);

    return 0;
}

