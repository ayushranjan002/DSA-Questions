#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    
    vector<int> arr;
    while(!myStack.empty()){
        arr.push_back(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    for(int i = arr.size()-1 ; i >= 0 ; i--){
        myStack.push(arr[i]);
    }
    return myStack;
}

//<======================================== Recursion ==========================================>
void insertAtBottom(stack<int> &stack , int x) {
    // base case: if the stack is empty, push the element x
    if(stack.empty()) {
        stack.push(x);
        return;
    }
    
    // store the top element and remove it from the stack
    int num = stack.top();
    stack.pop();
    
    // recursive call to insert x at the bottom
    insertAtBottom(stack, x);
    
    // after the recursive call, push the stored element back onto the stack
    stack.push(num);
}
