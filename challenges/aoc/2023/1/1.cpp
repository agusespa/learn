#include <ctype.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "Failed opening file." << std::endl;
        return 1;
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        char first = 'x';
        char last = 'x';

        for (int i = 0; i < line.length(); i++) {
            char currentChar = line[i];
            if (isdigit(currentChar)) {
                if (first == 'x') {
                    first = currentChar;
                } else
                    last = currentChar;
            }
        }

        if (last == 'x') {
            last = first;
        }

        int n = ((first - '0') * 10) + (last - '0');
        count += n;

    }

    file.close();

    std::cout << "result: " << count;

    return 0;
}

