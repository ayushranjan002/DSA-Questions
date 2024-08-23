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
void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);

    insertAtBottom(stack,num);
}
