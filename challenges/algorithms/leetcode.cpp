#include <iostream>
using namespace std;

char repeatedCharacter(string s) {
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        int j = int(s[i]) - 97;
        arr[j]++;
        if (arr[j] == 2) return s[i];
    }

    return 0;
}

int main() {
    char answer = repeatedCharacter("abcdd");

    cout << answer << endl;

    // for (size_t i = 0; i < s.size(); ++i) {
    //     std::cout << s[i] << " ";
    // }

    return 1;
}

