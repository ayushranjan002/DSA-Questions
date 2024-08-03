/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
int getLength(ListNode* head) {
    int cnt = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = getLength(head) / 2;
        ListNode* temp = head;
        while (len > 0) {
            temp = temp->next;
            len--;
        }
        return temp;
    }
};
