class Solution {
    int maxPathDown(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = max(0, maxPathDown(root->left, maxSum));
        int rightSum = max(0, maxPathDown(root->right, maxSum));
        
        maxSum = max(maxSum, root->val + leftSum + rightSum);
        
        return root->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }
};