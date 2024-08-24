
bool findRedundantBrackets(string &s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];  // Corrected to access the string 's'
        
        // Push operators and opening brackets onto the stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } 
        else {
            // Check for closing bracket ')'
            if(ch == ')') {
                bool isRedundant = true;
                
                // Pop elements until opening bracket '(' is found
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;  // If an operator is found, the bracket isn't redundant
                    }
                    st.pop();
                }
                
                // Pop the opening bracket '('
                st.pop();
                
                // If no operator was found between the brackets, they are redundant
                if(isRedundant) {
                    return true;
                }
            }
        }
    }
    return false;
}
