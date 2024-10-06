/*Q1. Maximum Possible Number by Binary Concatenation
Solved
Medium
4 pt.
You are given an array of integers nums of size 3.

Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.

Note that the binary representation of any number does not contain leading zeros.

 

Example 1:

Input: nums = [1,2,3]

Output: 30

Explanation:

Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.

Example 2:

Input: nums = [2,8,16]

Output: 1296

Explanation:

Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.

 

Constraints:

nums.length == 3
1 <= nums[i] <= 127

CODE:
*/

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaryStrings;

        // Convert each number to its binary representation (without leading zeros)
        for (int num : nums) {
            if (num > 0) {
                string binary = std::bitset<32>(num).to_string(); // Get 32-bit binary representation
                binaryStrings.push_back(binary.substr(binary.find('1'))); // Remove leading zeros
            } else if (num == 0) {
                binaryStrings.push_back("0");
            }
        }

        // Sort binary strings in a way to maximize the result when concatenated
        sort(binaryStrings.begin(), binaryStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // Concatenate the sorted binary strings
        string result;
        for (const string& binary : binaryStrings) {
            result += binary;
        }

        // Convert the concatenated binary string back to an integer
        long long decimalValue = 0;
        for (char c : result) {
            decimalValue = (decimalValue << 1) | (c - '0');
        }

        // Check for overflow and return the result
        if (decimalValue > INT_MAX) {
            return -1; // Indicate overflow
        }

        return static_cast<int>(decimalValue);
    }
};
