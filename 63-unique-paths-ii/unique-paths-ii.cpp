class Solution {
public:
    int f(int sr, int sc, int m, int n,vector<vector<int>> grid, vector<vector<int>> &dp){
        if(sr >= m || sc >= n || grid[sr][sc] == 1)
            return 0;
        
        if(sr == m-1 && sc == n-1)
            return 1;
        
        if(dp[sr][sc] != -1)
            return dp[sr][sc];
        
        int r = 0,d = 0;
        if(grid[sr][sc] != 1){
            r = f(sr,sc+1,m,n,grid,dp);
            d = f(sr+1,sc,m,n,grid,dp);
        }
        return dp[sr][sc] = r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return f(0,0,m,n,grid,dp);
    }
};