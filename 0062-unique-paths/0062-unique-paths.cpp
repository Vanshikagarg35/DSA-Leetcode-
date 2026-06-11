class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1));
        for(int row=0; row<m+1; row++){
            t[row][0]=0;
        }
        for(int col=0; col<n+1; col++){
            t[0][col]=0;
        }
        for(int row = 1; row<m+1; row++){
            for(int col = 1; col < n+1; col++){
                if(row == 1 && col == 1) t[row][col]=1;
                else{
                    t[row][col] = t[row-1][col] + t[row][col-1];
                }
                
            }
        }
        return t[m][n];
    }
};