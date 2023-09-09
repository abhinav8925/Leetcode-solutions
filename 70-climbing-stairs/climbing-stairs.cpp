// Problem Link -> https://leetcode.com/problems/climbing-stairs/

class Solution {
public:

    int count(int n,vector<int> &dp){
        if(n<=2)
            return n;
        
        
        if(dp[n]!=-1)
            return dp[n];
        
        dp[n] = count(n-1,dp) + count(n-2,dp);
    
        return dp[n];
    }


    int climbStairs(int n) {
        
        if(n<=2)
            return n;

        vector<int> dp(n+1,-1);

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        count(n,dp);

        return dp[n];
    }
};