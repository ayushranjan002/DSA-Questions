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

int firstoccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + ((e - s) / 2);
	int ans;
    while (s <= e) {
      
        if (arr[mid] == key) {
            ans=mid;
            e=mid-1;
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }

    return ans;
}

int lastoccurence(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + ((e - s) / 2);
	int ans;
    while (s <= e) {
      
        if (arr[mid] == key) {
            ans=mid;
            s=mid+1;
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + ((e - s) / 2);
    }

    return ans;
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

    cout << "Enter elements of array1:" << endl;
    createArray(arr1, n);

    cout << "The elements of array1 are:" << endl;
    printArray(arr1, n);

    cout << "Enter element to be searched: ";
    cin >> key;

    
    cout << "The element's first  occurrence at index "  << firstoccurence(arr1,n,key)<< " and last occurence at index "<< lastoccurence(arr1,n,key)<<endl;

    return 0;
}
