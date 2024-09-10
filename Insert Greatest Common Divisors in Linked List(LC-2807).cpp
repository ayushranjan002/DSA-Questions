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
    int gcd(int x , int y){
        if(x < y){
            int result = x;
            while(result > 0){
                if(x % result == 0 && y % result == 0){
                break;
                }
                result--; 
            }
            return result;
        }
        else{
            int result = y;
            while(result > 0){
                if(x % result == 0 && y % result == 0){
                break;
                }
                result--; 
            }
            return result;
        }
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp->next != NULL){
            int ans = gcd(temp->val, temp->next->val);
            ListNode* t = new ListNode(ans);
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }
        return head;
    }
};
