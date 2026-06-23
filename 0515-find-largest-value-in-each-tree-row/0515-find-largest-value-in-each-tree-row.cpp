#include <vector>
#include <algorithm> // max_element ke liye

using namespace std;

class Solution {
public:
    
    void traverse(TreeNode* root, int level, vector<vector<int>>& ans){
        if(root == NULL) return;
        
        if(ans.size() == level) {
            ans.push_back(vector<int>());
        }
        
        ans[level].push_back(root->val);
        
        
        traverse(root->left, level + 1, ans);
        traverse(root->right, level + 1, ans);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> result;
        
        traverse(root, 0, ans);
        
        for(int i = 0; i < ans.size(); i++){
            
            int maxl = *max_element(ans[i].begin(), ans[i].end());
            result.push_back(maxl);
        }
        
        return result;
    }
};