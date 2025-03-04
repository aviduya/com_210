#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
    int comparison_ammount = 0;
    for(int i = 0; i < size; i++) {
        comparison_ammount++;
        if (arr[i] == target) {
            return comparison_ammount;
        }
    }
    return comparison_ammount;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int comparison_amount = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow
        comparison_amount++;

        if (arr[mid] == target) {
            break;
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return comparison_amount; // Return -1 if target is not found
}

int main() {
    srand(time(0));
    const int SIZE = 1000;
    int arr[SIZE] = {};


    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }

    cout << "Linear Search\n============\n";
    int totalComparisons = 0;
    for (int i = 0; i <= 9; i++) {
        int target = rand() % 1000;
        int comparisons = linearSearch(arr, SIZE, target);
        totalComparisons += comparisons;

        cout << "#" << i  + 1 << " | " << comparisons << "\n";
    }
    cout << "Average\t" << totalComparisons / 10 << "\n\n";

    cout << "Binary Search\n============\n";
    totalComparisons = 0;
    for (int i = 0; i <= 9; i++) {
        int target = rand() % 1000;
        int comparisons = binarySearch(arr, SIZE, target);
        totalComparisons += comparisons;

        cout << "#" << i  + 1 << " | " << comparisons << "\n";
    }
    cout << "Average\t" << totalComparisons / 10 << "\n\n";

    return 0;
}
