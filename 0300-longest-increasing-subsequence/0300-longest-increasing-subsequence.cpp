class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(n + 1, -1));
        return solve(nums, t, -1, 0, n);
    }
    
    int solve(vector<int>& nums, vector<vector<int>>& t, int previdx, int curridx, int n){
        if(curridx == n) return 0;
        
        if(previdx != -1 && t[previdx][curridx] != -1){
            return t[previdx][curridx];
        }
        
        int taken=0;
        if(previdx == -1 || nums[curridx] > nums[previdx]){
            taken = 1 + solve(nums, t, curridx, curridx + 1, n);
        }
        
        int notaken = solve(nums, t, previdx, curridx + 1, n);
        
        if(previdx != -1){
            t[previdx][curridx] = max(taken, notaken);
        }
        
        return max(taken, notaken);
    }
};