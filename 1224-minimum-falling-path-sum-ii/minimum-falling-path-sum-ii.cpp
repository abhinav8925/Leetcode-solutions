// Problem Link -> https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:

    int f(int last,int i,vector<vector<int>>& grid,vector<vector<int>>& dp){

        if(i==grid.size())
            return 0;
        
        if(dp[i][last]!=-1)
            return dp[i][last];
        
        int ans = INT_MAX;

        for(int h=0;h<grid[0].size();h++){

            if(h!=last){
                ans = min(ans, f(h,i+1,grid,dp) + grid[i][h]);
            }
        }

        return dp[i][last] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        

        int n = grid.size();

        vector<vector<int>> dp(n,vector<int> (n,-1));

        if(n==1)
            return grid[0][0];
        
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            ans = min(ans, f(i,0,grid,dp));
        }

        return ans;
    }
};