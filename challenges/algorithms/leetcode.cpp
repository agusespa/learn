#include <iostream>
using namespace std;

int map(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        char n = s[i + 1];

        if (map(c) < map(n)) {
            sum -= map(c);
        } else {
            sum += map(c);
        }
    }

    return sum;
}

int main() {
    int number = romanToInt("MCMXCIV");

    cout << number << endl;

    // for (size_t i = 0; i < s.size(); ++i) {
    //     std::cout << s[i] << " ";
    // }

    return 1;
}

