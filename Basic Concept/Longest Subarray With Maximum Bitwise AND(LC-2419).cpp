//39 min brute + optimized
// optimized approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int c = 0;
        int maxlength = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];  
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxi){
                c++;
                maxlength = max(maxlength, c);
            }
            else{
                c = 0;
            }
        }
        return maxlength;
    }
};
//brute force
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;        
        int maxlength = 0;   

        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];  
            
            for(int j = i; j < nums.size(); j++) {
                temp &= nums[j];  

                if(temp > ans) {  
                    ans = temp;   
                    maxlength = j - i + 1;  
                } 
                else if(temp == ans) {  
                    maxlength = max(maxlength, j - i + 1);  
                }

                // Break the loop if temp becomes 0 since further ANDing will not help
                if(temp == 0) break;
            }
        }
        return maxlength;  
    }
};
