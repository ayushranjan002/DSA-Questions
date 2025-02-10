
void insertionSort(int arr[], int n){
    if(n==0 || n==1){
		return;
	}
    for(int i=0; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
int main() {
    int arr[] = {12, 56, 34, 52, 31, 21, 44, 87, 32, 79, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The sorted array is after using selection sort: "<<endl;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout << "The sorted array is after using bubble sort: "<<endl;
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    insertionSort(arr,n);
    cout<<" The sorted array is after using insertion sort "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
