#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

char match_string(string s) {
    if (s == "one") {
        return '1';
    } else if (s == "two") {
        return '2';
    } else if (s == "three") {
        return '3';
    } else if (s == "four") {
        return '4';
    } else if (s == "five") {
        return '5';
    } else if (s == "six") {
        return '6';
    } else if (s == "seven") {
        return '7';
    } else if (s == "eight") {
        return '8';
    } else if (s == "nine") {
        return '9';
    } else {
        return s[0];
    }
}

int find_first_last_digits(string s) {
    regex numberRegex("\\d|one|two|three|four|five|six|seven|eight|nine");
    regex reverseRegex("\\d|eno|owt|eerht|ruof|evif|xis|neves|thgie|enin");

    smatch match;
    char matched_first, matched_last;

    regex_search(s, match, numberRegex);
    matched_first = match_string(match.str());

    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    regex_search(reversed_s, match, reverseRegex);
    string reverseMatch = match.str();
    reverse(reverseMatch.begin(), reverseMatch.end());
    matched_last = match_string(reverseMatch);

    int n = ((matched_first - '0') * 10) + (matched_last - '0');
    return n;
}

int main() {
    ifstream file("input.txt");

    // for testing performance
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    string line;
    int result = 0;

    while (getline(file, line)) {
        result += find_first_last_digits(line);
    }

    cout << "Result: " << result << endl;

    // for testing performance
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::duration<double> elapsedSeconds = end - start;
    cout << "Execution Time: " << elapsedSeconds.count() << " seconds" << endl;
}

