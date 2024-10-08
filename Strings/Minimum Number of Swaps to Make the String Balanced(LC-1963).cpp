//cannot do it myself
class Solution {
public:
    int minSwaps(string s) {
        int close = 0; // Tracks unmatched `]`
        int imbalance = 0; // Tracks imbalance between open and close brackets
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '[') {
                close++; // Found an opening bracket
            } 
            else { // Found a closing bracket
                if (close > 0) {
                    close--; // Balance a pair of `[` and `]`
                } else {
                    imbalance++; // Found an unmatched `]`
                }
            }
        }
        
        // The number of swaps required to fix the imbalance is (imbalance + 1) / 2
        return (imbalance + 1) / 2;
    }
};
