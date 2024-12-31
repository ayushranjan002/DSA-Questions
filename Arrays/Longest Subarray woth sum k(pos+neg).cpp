  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        map<int,int> m;
        int maxlen = 0;
        int sum = 0;
        for(int i = 0;i<arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                maxlen = max(maxlen,i+1);
            }
            int rem = sum - k;
            if(m.find(rem) != m.end()){
                int len = i - m[rem];
                maxlen = max(maxlen,len);
            }
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }
        }
        return maxlen;
    }
};
method 2
class Solution {
public:
    int longestSubArrayWithSumK(vector<int>& nums, int K) {
        unordered_map<int, int> prefixSumIndices; // Maps prefix sum to its first occurrence index
        int maxLength = 0;                        // Stores the length of the longest subarray
        int currentSum = 0;                       // Tracks the cumulative sum of elements

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i]; // Update the cumulative sum

            // Check if the current cumulative sum equals K
            if (currentSum == K) {
                maxLength = max(maxLength, i + 1); // Update maxLength for subarray starting at index 0
            }

            // Check if removing a prefix sum gives a subarray with sum K
            if (prefixSumIndices.find(currentSum - K) != prefixSumIndices.end()) {
                int subArrayLength = i - prefixSumIndices[currentSum - K];
                maxLength = max(maxLength, subArrayLength);
            }

            // Store the first occurrence of the current cumulative sum
            if (prefixSumIndices.find(currentSum) == prefixSumIndices.end()) {
                prefixSumIndices[currentSum] = i;
            }
        }

        return maxLength;
    }
};
