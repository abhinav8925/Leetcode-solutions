// Problem Link -> https://leetcode.com/problems/unique-paths/description/

#define ll long long int

class Solution {
public:
ll count(int row,int col,int m,int n,vector<vector<ll>> &dp){
        
        
        if(row == m  && col==n)
            return 1;
            
        if(row>m || col>n)
            return 0;
        
        
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        
        return dp[row][col] =  (count(row+1,col,m,n,dp) + count (row,col+1,m,n,dp));
        
        
            
    
        
    }
    int uniquePaths(int m, int n) {
        

        vector<vector<ll>> dp(m+1,vector<ll> (n+1,-1));
        
        int row=0,col=0;
        
        
        return count (0,0,m-1,n-1,dp);
    }
};