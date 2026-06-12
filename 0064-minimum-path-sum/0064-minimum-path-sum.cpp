class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m+1,vector<int>(n+1,1e9));
        return solve(grid,m,n, t);
    }
    int solve(vector<vector<int>> &grid,int m, int n, vector<vector<int>>& t){
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(i==1 && j==1) t[1][1] = grid[0][0];
                else{
                    int right = grid[i-1][j-1] + t[i-1][j];
                    int down = grid[i-1][j-1] + t[i][j-1];
                    t[i][j] = min(right , down);
                }
            }
        }
        return t[m][n];
    }
};