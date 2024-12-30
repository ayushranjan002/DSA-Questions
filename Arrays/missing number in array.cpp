//O(n),O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n+1; i++){
            sum += i;
        }
        int sum1=0;
        for(int i = 0; i < nums.size();i++){
            sum1 += nums[i];
        }
        return sum-sum1;
    }
};
//O(nlogn),O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(i != nums[i]) {
                return i;
            }
        }
        return n;
    }
};

