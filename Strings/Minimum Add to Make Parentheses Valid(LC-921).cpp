class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        
        for(char c : s) {
            if(c == '(') {
                open++;
            } 
            else {
                // If there's an unmatched '(', match it, otherwise it's an extra ')'
                if(open > 0) {
                    open--;
                } else {
                    close++;
                }
            }
        }
        
      
        return open + close;
    }
};
