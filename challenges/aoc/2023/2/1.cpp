#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // ifstream file("sample.txt");
    ifstream file("input.txt");

    string line;
    int count = 0;

    while (getline(file, line)) {
        int id = 0;

        for (int block = 6; block < line.length(); ++block) {
            if (line[block] == ':') {
                id = stoi(line.substr(5, block - 5));
                line = line.substr(block + 1);
                break;
            }
        }

        istringstream ss(line);
        vector<string> mainBlocks;

        while (getline(ss, line, ';')) {
            mainBlocks.push_back(line);
        }

        bool isValid = true;

        for (string& block : mainBlocks) {
            int red = 0, green = 0, blue = 0;
            istringstream subSS(block);
            string subBlock;

            while (getline(subSS, subBlock, ',')) {
                istringstream colorSS(subBlock);
                int value;
                string color;

                colorSS >> value >> color;

                if (color[0] == 'r') {
                    red += value;
                } else if (color[0] == 'g') {
                    green += value;
                } else if (color[0] == 'b') {
                    blue += value;
                }
            }

            if (red > 12 || green > 13 || blue > 14) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            count += id;
        }
    }

    file.close();

    cout << "Result: " << count << endl;

    return 0;
}

