/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* >q;
        vector<vector<int>>ans;
        vector<int>pair;
        if(root!=NULL){
            q.push(root);
            pair.push_back(root->val);
            ans.push_back(pair);

        }
        else{
            return ans;
        }
        while(!q.empty()){
            int size = q.size();
            vector<int>pair;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                TreeNode* left = temp->left;
                if(left!=NULL){
                    q.push(left);
                    pair.push_back(left->val);
                }
                TreeNode* right = temp->right;
                if(right!=NULL){
                    q.push(right);
                    pair.push_back(right->val);
                }
                
            }
            if(pair.size()!=0) ans.push_back(pair);
        }
        return ans;
    }
};