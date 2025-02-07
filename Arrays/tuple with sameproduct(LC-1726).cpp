class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if(nums.size() < 4) return 0;
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {  // Ensure i < j to avoid duplicates
                m[nums[i] * nums[j]]++;
            }
        }
        
        int cnt = 0;
        for( auto &i : m) {
            if(i.second >= 2) {  
                
                cnt += 8 * (i.second * (i.second - 1) / 2);  /*this cond
                ition is used to find the permutions if a product occured more
                 than 2 times*/
            }
        }
        return cnt;
    }
};
