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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return nullptr; // If the list is empty, return nullptr
        
        // Convert nums vector into a set for O(1) lookup time
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Use dummy node to handle deletion of head node easily
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (numSet.count(current->val)) {
                // Node needs to be deleted
                prev->next = current->next;
                delete current;  // Free memory
                current = prev->next;  // Move to the next node
            } else {
                // Move both prev and current forward
                prev = current;
                current = current->next;
            }
        }
        
        // Get the new head and delete the dummy node
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};

//brute force
class Solution {
public:
    // Function to delete the node and return the new head of the list
    ListNode* deleteNode(ListNode* head, ListNode* nodeToDelete) {
        if (head == nodeToDelete) {
            // If the node to delete is the head, move the head forward
            head = head->next;
            delete nodeToDelete;
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* temp = head;
        // Find the previous node of the node to delete
        while (temp != nullptr && temp != nodeToDelete) {
            prev = temp;
            temp = temp->next;
        }
        
        // If node was found
        if (temp == nodeToDelete) {
            prev->next = temp->next;
            delete temp;
        }
        
        return head;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for (int i = 0; i < nums.size(); i++) {
            ListNode* temp = head;
            while (temp != nullptr) {
                if (temp->val == nums[i]) {
                    head = deleteNode(head, temp);
                    // After deleting the node, restart the loop for safety
                    temp = head;
                } else {
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};
