#include <ctype.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // ifstream file("sample.txt");
    ifstream file("input.txt");

    // for testing performance
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    string line;
    int count = 0;

    while (getline(file, line)) {
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

    cout << "result: " << count;

    // for testing performance
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsedSeconds = end - start;
    cout << "Execution Time: " << elapsedSeconds.count() << " seconds" << endl;

    return 0;
}

