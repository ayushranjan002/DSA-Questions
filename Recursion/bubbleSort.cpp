#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
	if(n==0 || n==1){
		return;
	}
	for(int i=1;i<n;i++){
		if(arr[i] < arr[i-1]){
			swap(arr[i],arr[i-1]);
		}
	}
	bubbleSort(arr,n-1);
}
int main(){
	int arr[]={12,56,34,52,31,21,44,87,32,79,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"the sorted array is"<<endl;
	bubbleSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
