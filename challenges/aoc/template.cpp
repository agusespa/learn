#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main() {
    ifstream file("sample.txt");
    // ifstream file("input.txt");

    // for testing performance
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    string content;
    string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    file.close();

    cout << "File content:\n" << content;

    // for testing performance
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsedSeconds = end - start;
    cout << "Execution Time: " << elapsedSeconds.count() << " seconds" << endl;

    return 0;
}
