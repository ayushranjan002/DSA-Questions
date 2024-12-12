#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;
        
        for (int i = 0; i < k; ++i) {
            sort(gifts.begin(), gifts.end());
            //static_cast<int>(...) converts the result of sqrt() from double to int, effectively truncating any decimal part. This means the result is rounded down (floor behavior).
            gifts[gifts.size() - 1] = static_cast<int>(sqrt(gifts[gifts.size() - 1]));
        }
        
        for (int gift : gifts) {
            result += gift;
        }
        
        return result;
    }
};
