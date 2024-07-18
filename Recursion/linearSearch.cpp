#include <iostream>
#include <climits> // Include this for INT_MIN and INT_MAX
using namespace std;

void createArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[],int size,int x){
	printArray(arr,size);
	if(size==0||size<0){
		return false;
	}
	else if(arr[0]==x){
		return true;
	}

	else{
		int ans=linearSearch(arr+1,size-1,x);
		return ans;
	}
	
}

int main() {
    int arr1[10];
    int n; // size of array
    cout << "Enter size of array1:" << endl;
    cin >> n;
    
    if(n > 10) {
        cout << "Size of array should not exceed 10." << endl;
        return 1;
    }

    cout << "Enter elements of array1:" << endl;
    createArray(arr1, n);

    cout << "The elements of array1 are:" << endl;
    printArray(arr1, n);

    cout << "Enter element to be searched:" << endl;
    int x;
    cin >> x;
      bool result=linearSearch(arr1,n,x);
    cout<<"whether element is present "<<result;
    

    return 0;
}
