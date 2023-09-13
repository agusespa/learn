#include <stdio.h>
#include <time.h>

int getShape(char shape) {
    switch (shape) {
        case 'A':
        case 'X':
            return 1;
        case 'B':
        case 'Y':
            return 2;
        case 'C':
        case 'Z':
            return 3;
        default:
            printf("Invalid shape: %c\n", shape);
            return -1;
    }
}

int main() {
    char opponent[4];
    char response[4];

    FILE *file = fopen("input2.txt", "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // only for testing performance
    clock_t start = clock();

    int totalScore = 0;

    // only for testing performance
    for (int i = 0; i < 100000000; i++) {

        while (fscanf(file, "%s %s", opponent, response) != EOF) {
            int opponentShape = getShape(opponent[0]);
            int responseShape = getShape(response[0]);

            if (opponentShape == -1 || responseShape == -1) {
                fclose(file);
                return 1;
            }

            int score;
            if (opponentShape == responseShape) {
                score = 3;
            } else if ((opponentShape == 1 && responseShape == 3) ||
                       (opponentShape == 2 && responseShape == 1) ||
                       (opponentShape == 3 && responseShape == 2)) {
                score = 0;
            } else {
                score = 6;
            }

            totalScore += score + responseShape;
        }
    }

    // only for testing performance
    clock_t end = clock();
    double elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed Time: %.6f seconds\n", elapsedSeconds); // 5.569 sec on 2016 MacBook

    fclose(file);

    printf("%d\n", totalScore);

    return 0;
}

