class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zerocnt = 0;
        int onecnt = 0;
        int twocnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0) 
                zerocnt++;
            if(nums[i]==1) 
                onecnt++;
            if(nums[i]==2) 
                twocnt++;
        }
        for(int i = 0; i < zerocnt;i++){
            nums[i] = 0;
        }
        for(int i = zerocnt; i < (zerocnt+onecnt);i++){
            nums[i] = 1;
        }
        for(int i = (zerocnt+onecnt); i < nums.size();i++){
            nums[i] = 2;
        }
        return ;
    }
};
