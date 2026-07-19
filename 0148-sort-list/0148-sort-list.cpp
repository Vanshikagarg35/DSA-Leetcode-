class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        vector<int> vals;
        ListNode* curr = head;
        
        while (curr != NULL) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(vals.begin(), vals.end());
        
        curr = head;
        int i = 0;
        while (curr != NULL) {
            curr->val = vals[i];
            curr = curr->next;
            i++;
        }
        
        return head;
    }
};