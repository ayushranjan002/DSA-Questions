class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*
        Algorithm:
        xor goal and start to get no of different digits ie 1's and then calculate number of 1's 
        */
        int ans = 0;
        int result = start ^ goal;
        while(result != 0){
            if(result & 1){
                ans++;
            }
            result = result >> 1;
        }
        return ans;
    }
};
