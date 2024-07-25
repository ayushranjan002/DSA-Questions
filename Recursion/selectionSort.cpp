#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }
    
    // Find the index of the minimum element in the unsorted part
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the minimum element with the first element
    swap(arr[0], arr[minIndex]);

    // Recursively sort the remaining array
    selectionSort(arr + 1, n - 1);
}

int main() {
    int arr[] = {12, 56, 34, 52, 31, 21, 44, 87, 32, 79, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The sorted array is: ";
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
