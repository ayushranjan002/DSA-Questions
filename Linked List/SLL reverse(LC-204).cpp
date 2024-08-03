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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward;
        while(curr != nullptr){
            forward = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};


<================ RECURSION ===================>
void reverse(ListNode** head, ListNode* curr, ListNode* prev){
    if(curr == nullptr){
        *head = prev;
        return;
    }
    ListNode* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        reverse(&head, curr, prev);
        return head;
    }
};
