
class Solution {
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        ListNode* temp = new ListNode(val);
        
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = nullptr;
        ListNode* ansTail = nullptr;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            // Create a new node with the digit and add it to the result list
            insertAtTail(ansHead, ansTail, digit);
            
            // Update the carry
            carry = sum / 10;
            
            // Move to the next nodes
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return ansHead;
    }
};
