class Solution {
public:
    int f(int sr, int sc, int m, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(sr >= m)
            return 0;
        if(sr == m-1)
            return grid[sr][sc];
        
        if(dp[sr][sc] != INT_MAX)
            return dp[sr][sc];
        
        int down = grid[sr][sc] + f(sr+1,sc,m,grid,dp);
        int diag = grid[sr][sc] + f(sr+1,sc+1,m,grid,dp);

        return dp[sr][sc] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        
        int m = grid.size();
        // return f(0,0,m,grid,dp);
        vector<vector<int>> dp(m, vector<int> (m,0));
        dp[0][0] = 0;

        for(int j=m-1;j>=0;j--)
            dp[m-1][j] = grid[m-1][j];

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up = grid[i][j] + dp[i+1][j];
                int diag = grid[i][j] + dp[i+1][j+1];

                dp[i][j] = min(up,diag);
            }
        }
        return dp[0][0];
    }
};