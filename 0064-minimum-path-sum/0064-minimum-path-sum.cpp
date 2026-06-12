class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return solve(0,0,grid,m,n,t);
    }
    int solve(int i, int j, vector<vector<int>>& grid , int m, int n, vector<vector<int>>& t){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1e9;;
        }
        if(i==m-1 && j==n-1) return grid[i][j];
        if(t[i][j]!=-1) return t[i][j];

        int right = grid[i][j]+solve(i+1, j,grid, m, n, t);
        int down = grid[i][j]+solve(i, j+1,grid, m, n, t);
        return t[i][j]=min(right , down);
    }
};