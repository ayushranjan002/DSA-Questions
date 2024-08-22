#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
	int i;//used to find index of middle element
   if(N%2 == 0){
       i = N/2 - 1;
   }
   else{
      i = (N+1)/2 -1;
   }
   vector<int> arr;//temporery element to store the element of popped eleemnts
   int x = N-1;
   while(x > i){
      int t = inputStack.top();
      arr.push_back(t);
      x--;
      inputStack.pop();
   }
   inputStack.pop();//removing middle element
   
   for(int j = arr.size() - 1; j >= 0; j--){
         
         inputStack.push(arr[j]);//restoring the popped elements
   }
}
