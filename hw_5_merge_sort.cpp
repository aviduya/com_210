// Part 2:
// What is the time complexity of Merge Sort?
// The answer would be O(N Log N)

// What would be the estimated number of key comparisons when the size of the array is 100?
// The answer would be about 664 Comparisons.

// Compare the estimated number with the x11 that you obtained from Part 1. Are these two numbers pretty close?
// Yes, espcially for a random set amount of numbers.

// Part 1:
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

const int SIZE = 100;
const int RANGE_MAX = 1000;
int COMPARISONS;

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two halves back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        COMPARISONS += 1;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // Sort the left half of the array
        mergeSort(arr, mid + 1, right); // Sort the right half of the array

        merge(arr, left, mid, right); // Merge 2 sorted arrays
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int repeatSteps() {
    COMPARISONS = 0;
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % RANGE_MAX);
    }

    mergeSort(arr, 0, SIZE - 1);

    return COMPARISONS;
}

// Main function to test Merge Sort
int main() {
    srand(time(0));
    unordered_map<int, int> table_runs;

    int total = 0;

    cout << setw(8) << "Run #" << " | " << setw(12) << "Comparisons" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < 10; i++) {
        table_runs[i] = repeatSteps();
        total += table_runs[i];
        cout << "| " << setw(5) << i + 1 << " | " << setw(12) << table_runs[i] << " |\n";
    }

    cout << "\nAverage comparisons: " << total / 10.0 << endl;

    return 0;
}
