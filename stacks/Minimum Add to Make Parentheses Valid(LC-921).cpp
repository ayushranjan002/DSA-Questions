class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
    
        }
        int count = 0;
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};
