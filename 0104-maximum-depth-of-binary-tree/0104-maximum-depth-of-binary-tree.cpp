class Solution {
    void countMax(TreeNode* root, int currentCount, int &maxCount) {
        if (root == nullptr) {
            return;
        }
        
        currentCount++;
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
        
        countMax(root->left, currentCount, maxCount);
        countMax(root->right, currentCount, maxCount);
    }

public:
    int maxDepth(TreeNode* root) {
        int maxCount = 0;
        countMax(root, 0, maxCount);
        return maxCount;
    }
};