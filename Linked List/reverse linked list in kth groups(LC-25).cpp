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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes left in the linked list
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == nullptr) return head;
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* forward = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // Recurse on the remaining linked list
        if (forward != nullptr) {
            head->next = reverseKGroup(forward, k);
        }

        // Return the new head of the reversed linked list
        return prev;
    }
};
