class Solution {
public:
    long long f(vector<vector<int>> &grid, int sr,int sc, int n,vector<vector<long long>> &dp){
        if(sr >= n || sc >=n)
            return INT_MAX;
        
        if(sr == n-1)
            return grid[sr][sc];

        if(dp[sr][sc] != INT_MAX)
            return dp[sr][sc];
        
        long long down = grid[sr][sc] + f(grid,sr+1,sc,n,dp);
        long long left_diag = INT_MAX;
        if(sc>0)
            left_diag = grid[sr][sc] + f(grid,sr+1,sc-1,n,dp);
        long long right_diag = INT_MAX;
        if(sc<n)
            right_diag = grid[sr][sc] + f(grid,sr+1,sc+1,n,dp);
        
        return dp[sr][sc] = (int)min({down,left_diag,right_diag});
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<long long>> dp(n,vector<long long> (n,INT_MAX));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int temp = (int)f(grid,0,i,n,dp);
            ans = min(ans,temp);
        }
        return ans;
    }
};