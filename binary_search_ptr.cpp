#include <iostream>
#include <math.h>
#include <cstdlib>

bool binarySearch(int list[], int size, int target) {
    int *first = &list[0];
    int *last = &list[size - 1];

    while (last >= first) {
        // Calculating the mid - using memory address and pointer to the first element in the list.
        int mid = ((first - &list[0]) + (last - &list[0]))/2;

        if (list[mid] == target) {
            return true;
        } else {
            if (mid > 0 && target < list[mid]) {
                // last = list[mid - 1]; invalid conversion from 'int' to 'int*'
                last = &list[mid - 1];
            } else if (mid < size - 1 && target > list[mid]) {
                first = &list[mid + 1];
            }
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    // run the binarySearch function.
    int list[7] = {8, 11, 12, 34, 51, 55, 109};
    bool result = binarySearch(list, sizeof(list)/sizeof(int), 12);
    std::cout << "Result: " << std::boolalpha << result << "\n";
    return 0;
}