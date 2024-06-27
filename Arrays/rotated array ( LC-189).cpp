class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //we use new vector to avoid overwrite poblem which occurs if we do in the same vector
        vector<int> temp(nums.size());
        /*
        shifting every element to kth spaces but for (n-1)th element cannot be shifted 
        forward so it goes in cyclic order ie it goes to 0th index and for that we use 
        mod function as we know mod function range is from 0 to n-1 and that what we want
        for the cyclic order position(to start from 0th index again).
       */
        for(int i=0;i< nums.size() ;i++){
            temp[(i+k) % nums.size()] = nums[i];
        }
        nums=temp;
    }
};
