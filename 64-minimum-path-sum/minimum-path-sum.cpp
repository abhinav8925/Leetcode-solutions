class Solution {
public:
    long long f(int sr, int sc, int m, int n, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(sr >= m || sc >= n)
            return INT_MAX;
        
        if(sr == m-1 && sc == n-1)
            return grid[sr][sc];
        
        if(dp[sr][sc] != -1)
            return dp[sr][sc];

        long long d = grid[sr][sc] + f(sr+1,sc,m,n,grid,dp);
        long long r = grid[sr][sc] + f(sr,sc+1,m,n,grid,dp);

        return dp[sr][sc] = (int)min(r,d);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(0,0,m,n,grid,dp);
    }
};