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

bool isSorted(int arr[],int size){
	if(size==1||size==0){
		return true;
	}
	else if(arr[0]>arr[1]){
		return false;
	}
	else{
		bool ans=isSorted(arr+1,size-1);
		return ans;
	}
	
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
	bool ans=isSorted(arr1,n);
    cout << "Checking if the array is sorted and it is "<<ans;
    
    

   
    return 0;
}
