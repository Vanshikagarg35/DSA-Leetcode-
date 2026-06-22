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
    int countMax(TreeNode* root,int count){
        if(root==NULL)return 0;
        int leftcount = countMax(root->left, count);
        int rightcount= countMax(root->right, count);
        return max(leftcount,rightcount)+1;

    }
    int maxDepth(TreeNode* root) {
        int count=0;
        count = countMax(root, 0);
        return count;
    }
};