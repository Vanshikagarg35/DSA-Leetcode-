class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else {
                TreeNode* child = root->left;
                TreeNode* parent = root;

                while (child->right) {
                    parent = child;
                    child = child->right;
                }

                if (root != parent) {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                } else {
                    child->right = root->right;
                }

                delete root;
                return child;
            }
        }
        
        return root;
    }
};