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
        for (int block = 6; block < line.length(); ++block) {
            if (line[block] == ':') {
                line = line.substr(block + 1);
                break;
            }
        }

        istringstream ss(line);
        vector<string> mainBlocks;

        int maxRed = 0, maxGreen = 0, maxBlue = 0;

        while (getline(ss, line, ';')) {
            mainBlocks.push_back(line);
        }

        for (string& block : mainBlocks) {
            istringstream subSS(block);
            string subBlock;
            int red = 0, green = 0, blue = 0;

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

            maxRed = maxRed < red ? red : maxRed;
            maxBlue = maxBlue < blue ? blue : maxBlue;
            maxGreen = maxGreen < green ? green : maxGreen;
        }

        count += maxRed * maxGreen * maxBlue;
    }

    file.close();

    cout << "Result: " << count << endl;

    return 0;
}

