
#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    // Base case
    if (stack.empty() || num >= stack.top()) {
        stack.push(num);
        return;
    }

    //  pop the top element and recurse
    int temp = stack.top();
    stack.pop();
    sortedInsert(stack, num);


    stack.push(temp);
}

void sortStack(stack<int> &stack) {
    
    if (stack.empty()) {
        return;
    }

    // Pop the top element and sort the remaining stack recursively
    int num = stack.top();
    stack.pop();
    
    sortStack(stack);

    // Insert the popped element back in the sorted stack
    sortedInsert(stack, num);
}
