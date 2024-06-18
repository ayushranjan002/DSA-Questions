#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // Special case for 0
        if (n == 0) return 1;

        int m = n;
        int mask = 0;
        // Create a mask with all bits set to 1 up to the most significant bit of n
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        // XOR n with the mask to get the bitwise complement
        int ans = (~n) & mask;
        return ans;
    }
};
