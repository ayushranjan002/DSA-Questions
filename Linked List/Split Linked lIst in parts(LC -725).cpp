class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr){
            temp = temp->next;
            len++;
        }

        vector<ListNode*> ans;
        if(len < k){
            ListNode* curr = head;
            for(int i = 0; i < len; i++){
                ans.push_back(curr);
                ListNode* next = curr->next;
                curr->next = nullptr;
                curr = next;
            }
            for(int i = 0; i < (k - len); i++){
                ans.push_back(nullptr);
            }
        } else {
            int baseSize = len / k;
            int rem = len % k;
            ListNode* curr = head;
            for(int i = 0; i < k; i++){
                ans.push_back(curr);
                int partSize = baseSize + (i < rem ? 1 : 0);
                for(int j = 0; j < partSize - 1 && curr != nullptr; j++) {
                    curr = curr->next;
                }
                if(curr != nullptr){
                    ListNode* next = curr->next;
                    curr->next = nullptr;
                    curr = next;
                }
            }
        }
        return ans;
    }
};
