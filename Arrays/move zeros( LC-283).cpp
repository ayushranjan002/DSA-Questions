class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        while (j < n) {
            if (nums[i] != 0) {
                i++;
                j++;
            } else if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else {
                j++;
            }
        }
    }
};
