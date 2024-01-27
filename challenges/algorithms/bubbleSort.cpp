#include <iostream>

void sort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        bool swaped = false;

        for (int j = 0; j < size - 1 - i; ++j) {
            int a = arr[j];
            int b = arr[j + 1];
            if (a > b) {
                arr[j] = b;
                arr[j + 1] = a;
                swaped = true;
            }
        }

        if (!swaped) break;
    }
}

int main() {
    const int size = 100;
    int nums[size];

    for (int i = 0; i < size; ++i) {
        nums[i] = std::rand() % 1000;
    }

    sort(nums, size);

    for (int i = 0; i < size; ++i) {
        std::cout << nums[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }

    return 0;
}
