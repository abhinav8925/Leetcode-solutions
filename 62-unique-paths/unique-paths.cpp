class Solution {
public:
    // int f(int sr, int sc, int m, int n,vector<vector<int>> &dp){
    //     if(sr >= m || sc >= n)
    //         return 0;
        
    //     if(sr == m-1 && sc == n-1)
    //         return 1;
        
    //     if(dp[sr][sc] != -1)
    //         return dp[sr][sc];
        
    //     int r = f(sr,sc+1,m,n,dp);
    //     int d = f(sr+1,sc,m,n,dp);

    //     return dp[sr][sc] = r+d;
    // }
    int uniquePaths(int m, int n) {
        
        // return f(0,0,m,n,dp);

        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i>0)
                        up = dp[i-1][j];
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};