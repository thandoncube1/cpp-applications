#include <iostream>
#include <string>
#include <vector>
#include <math.h>

bool binarySearch(std::vector<int> list, int value) {
    int first = 0;
    int last = list.size() - 1;

    while (last > first) {
        int mid = floor((first + last) / 2);
        if (list[mid] == value) {
            return true;
        } else {
            if (value < list[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
    }

    return false;
}

int main() {
    std::vector<int> list = {5, 7, 12, 13, 20, 23, 23, 29, 58, 72, 73, 90};

    int result = binarySearch(list, 58);
    std::cout << "Search Result: " << result << "\n";
    return 0;
}