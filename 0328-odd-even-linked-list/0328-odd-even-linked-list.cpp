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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        int count=0;
        vector<int>evenIdx;
        vector<int>oddIdx;
        while(temp!=NULL){
            if(count%2==0){
                evenIdx.push_back(temp->val);
            }
            else{
                oddIdx.push_back(temp->val);
            }
            temp=temp->next;
            count++;

        }
        temp = head;
        while(temp!=NULL){
            int m = evenIdx.size();
            for(int i=0; i<m; i++){
                temp->val = evenIdx[i];
                temp=temp->next;
            }
            int n = oddIdx.size();
            for(int i=0; i<n; i++){
                temp->val = oddIdx[i];
                temp = temp->next;
            }
        }
        return head;
    }
};