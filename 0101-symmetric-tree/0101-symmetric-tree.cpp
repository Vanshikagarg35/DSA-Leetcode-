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
    bool isIdentical(TreeNode* r1 , TreeNode* r2){
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }
        
        if (r1 == nullptr || r2 == nullptr) {
            return false;
        }
        
        if (r1->val != r2->val) {
            return false;
        }
        
        bool leftAns = isIdentical(r1->left, r2->right);
        bool rightAns = isIdentical(r1->right, r2->left);
        return leftAns && rightAns;
       
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* r1 = root->left;
        TreeNode* r2 = root->right;
        bool result = isIdentical(r1 , r2);
        return result;
    }
};