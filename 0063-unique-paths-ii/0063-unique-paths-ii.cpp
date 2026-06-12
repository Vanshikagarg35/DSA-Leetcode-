class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& t){
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(obstacleGrid[i-1][j-1] == 1) {
                    t[i][j] = 0;
                } else if (i == 1 && j == 1) {
                    t[i][j] = 1;
                } else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        return t[m][n];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
        return solve(obstacleGrid, m, n, t);
    }
};