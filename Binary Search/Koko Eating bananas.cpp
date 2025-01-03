class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1; // Min speed
        int e = *max_element(piles.begin(), piles.end()); 
        int result = e;  

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long totalHours = 0;

            
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; 
            }

            if (totalHours <= h) {
                result = mid; 
                e = mid - 1;  
            } else {
                s = mid + 1; 
            }
        }

        return result;
    }
};
