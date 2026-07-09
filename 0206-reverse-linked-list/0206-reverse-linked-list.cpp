class Solution {
public:
    ListNode* reverseHelper(ListNode* temp, ListNode* prev) {
        if (temp == NULL) {
            return prev;
        }
        
        ListNode* front = temp->next;
        temp->next = prev;
        
        return reverseHelper(front, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverseHelper(head, NULL);
    }
};