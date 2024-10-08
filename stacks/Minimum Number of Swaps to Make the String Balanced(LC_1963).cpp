//very hard to think intuition for me
class Solution {
public:
    int minSwaps(string s) {
        int open = 0, imbalance = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                open++;
            } else if (s[i] == ']') {
                if (open > 0) {
                    open--; // Balance out a pair of brackets
                } else {
                    imbalance++; // Count imbalance where a `]` has no matching `[`
                }
            }
        }
        
        // Return the number of swaps required to balance
        return (imbalance + 1) / 2;
    }
};
