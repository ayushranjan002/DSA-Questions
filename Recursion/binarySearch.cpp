#include <iostream>
#include <climits> // Include this for INT_MIN and INT_MAX
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void createArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool binarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return true;

        // If x greater, ignore left half
        if (arr[mid] < x)
            return binarySearch(arr, mid + 1, right, x);

        // If x is smaller, ignore right half
        return binarySearch(arr, left, mid - 1, x);
    }

    // if we reach here, then element was not present
    return false;
}

int main() {
    int arr1[10];
    int n; // size of array
    cout << "Enter size of array1:" << endl;
    cin >> n;
    int key;

    if (n > 10) {
        cout << "Size of array should not exceed 10." << endl;
        return 1;
    }

    cout << "Enter elements of array1 in sorted order:" << endl;
    createArray(arr1, n);

    cout << "The elements of array1 are:" << endl;
    printArray(arr1, n);

    cout << "Enter element to be searched: ";
    cin >> key;

    bool result = binarySearch(arr1, 0, n - 1, key);
    if (result) {
        cout << "The element is found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
