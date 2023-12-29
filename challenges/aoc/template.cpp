#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "Failed opening file." << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    file.close();

    std::cout << "File content:\n" << content;

    return 0;
}

