/*
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int startrow = 0;
        int endrow = m - 1;
        int startcol = 0;
        int endcol = n - 1;
        ListNode* temp = head;

        while (startrow <= endrow && startcol <= endcol) {
            // Fill the top row
            for (int i = startcol; i <= endcol; i++) {
                if (temp != nullptr) {
                    ans[startrow][i] = temp->val;
                    temp = temp->next;
                }
            }
            startrow++;

            // Fill the right column
            for (int i = startrow; i <= endrow; i++) {
                if (temp != nullptr) {
                    ans[i][endcol] = temp->val;
                    temp = temp->next;
                }
            }
            endcol--;

            // Fill the bottom row
            if (startrow <= endrow) {
                for (int i = endcol; i >= startcol; i--) {
                    if (temp != nullptr) {
                        ans[endrow][i] = temp->val;
                        temp = temp->next;
                    }
                }
                endrow--;
            }

            // Fill the left column
            if (startcol <= endcol) {
                for (int i = endrow; i >= startrow; i--) {
                    if (temp != nullptr) {
                        ans[i][startcol] = temp->val;
                        temp = temp->next;
                    }
                }
                startcol++;
            }
        }

        return ans;
    }
};
