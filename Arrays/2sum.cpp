

    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
      
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(m.find(rem) != m.end()){ AGAR ELEMENT HAI
                ans.push_back(m[rem]); 
                ans.push_back(i);      
                return ans; 
            }
            m[nums[i]] = i;// Storing curr element with its index
        }
        return ans; 
    }
