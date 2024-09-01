#include <vector>
#include <stack>

std::vector<int> nextSmallerElement(std::vector<int> &arr, int n) {
    std::stack<int> s;
    s.push(-1);  // Initialize stack with -1
    std::vector<int> ans(n);

    // Iterate from right to left
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        
        // Pop elements from stack that are greater than or equal to the current element
        while (s.top() >= curr) {
            s.pop();
        }

        // The top of the stack is the next smaller element
        ans[i] = s.top();
        
        // Push the current element onto the stack
        s.push(curr);
    }

    return ans;
}
// brute force
#include <vector>
#include <climits>

std::vector<int> nextSmallerElement(std::vector<int> &arr, int n) {
    std::vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        int smallest = -1;  
        for (int j = i + 1; j < n; j++) {
          if (arr[j] < arr[i]) {
            smallest = arr[j];
            break; // Break as soon as we find a smaller element
          }
        }

        ans.push_back(smallest);
    }

    return ans;
}

