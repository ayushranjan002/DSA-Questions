#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the previous smaller element for each element in the array
    vector<int> prevSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while they are greater than or equal to arr[i]
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            // If the stack is empty, it means there is no smaller element on the left
            ans[i] = s.empty() ? -1 : s.top();
            
            // Push the current element index onto the stack
            s.push(i);
        }

        return ans;
    }

    // Function to find the next smaller element for each element in the array
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        vector<int> ans(n);

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are greater than or equal to the current element
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            // If the stack is empty, it means there is no smaller element on the right
            ans[i] = s.empty() ? n : s.top();
            
            // Push the current element index onto the stack
            s.push(i);
        }

        return ans;
    }

    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Find the indices of the previous and next smaller elements
        vector<int> prev = prevSmallerElement(heights, n);
        vector<int> next = nextSmallerElement(heights, n);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            // Calculate the width of the rectangle
            int width = next[i] - prev[i] - 1;

            // Calculate the area with heights[i] as the smallest height
            int area = heights[i] * width;

            // Update maxArea
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

//brute force
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0 ; i < n; i++){
            int left = i;
            int right = i;
            while(left >=0 && heights[left] >= heights[i]){
                left--;
            }
            while(right < n && heights[right] >= heights[i]){
                right++;
            }
            int w = (right - left - 1);
            int area = heights[i] * w;
            if(area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};
