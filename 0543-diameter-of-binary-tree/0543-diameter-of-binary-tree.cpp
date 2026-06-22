class Solution {
public:
    int countDia(TreeNode* root, int &maxDia) {
        if(root == NULL){
            return 0;
        }
        
        int leftCount = countDia(root->left, maxDia);
        int rightCount = countDia(root->right, maxDia);
        
        maxDia = max(maxDia, leftCount + rightCount);
        
        return max(leftCount, rightCount) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        countDia(root, maxDia);
        return maxDia;
    }
};