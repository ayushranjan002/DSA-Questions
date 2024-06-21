/*
#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}
*/
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
          if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
          }
        }
        counter++;
    }
}
