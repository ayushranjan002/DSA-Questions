//Best Solution T.C -- O(N) S.C---O(1)
class Solution {
    private:
        ListNode* getMid(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = head->next;

            while(fast!=NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }

        ListNode* reverse(ListNode* head){
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* forw = NULL;
            while(curr!=NULL){
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }

public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return true;
        }

        //step 1 : get mid
        ListNode* mid = getMid(head);

        //step2 : reverse node after middle
        ListNode* temp = mid->next;
        mid->next = reverse(temp);

        //step3 : compare both halves
        ListNode* head1 = head;
        ListNode* head2 = mid->next;
        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        //step 4  repeat step 2
        temp = mid->next;
        mid->next = reverse(temp);
        return true;
    }
};

//Needs Extra space
// T.C -- O(N) S.C-- O(N)
 #include<vector>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       // if(head == NULL){
       //     return true;
       // }
        vector<int> sol;

        ListNode* temp = head;
        while(temp != NULL){
            sol.push_back(temp->val);
            temp = temp->next;
        }

        int s = 0;
        int n = sol.size();
        int e = n-1;
        while(s<=e){

            if(sol[s] != sol[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};


