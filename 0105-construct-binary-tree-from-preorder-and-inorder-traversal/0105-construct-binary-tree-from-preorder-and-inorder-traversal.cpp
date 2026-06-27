class Solution {
public:
    int findPosition(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int& index) {
        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        
        int pos = findPosition(inorder, preorder[index], inStart, inEnd);
        
        index++; 

        root->left = construct(preorder, inorder, inStart, pos - 1, index);
        
        root->right = construct(preorder, inorder, pos + 1, inEnd, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return construct(preorder, inorder, 0, inorder.size() - 1, preIndex);
    }
};