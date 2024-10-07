#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char current : s) {
            // Checking for valid pairs 
            if (!st.empty() && 
                ((current == 'B' && st.top() == 'A') || 
                 (current == 'D' && st.top() == 'C'))) {
                st.pop();  // Pop the stack if the pair is valid
            } else {
                st.push(current);  // Push the current character if no valid pair
            }
        }

        // The size of the stack represents the remaining characters
        return st.size();
    }
};
