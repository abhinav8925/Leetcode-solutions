class Solution {
public:
    int mod  = 1e9+7;

    int f(int sp,int ep,int k,vector<vector<int>> &dp){

        if(k==0){
            return sp==ep;
        }

        
        if(dp[999+sp][k]!=-1)  
            return dp[999+sp][k];
        
        return dp[999+sp][k] = (f(sp+1,ep,k-1,dp)%mod + f(sp-1,ep,k-1,dp)%mod)%mod;
        

    }


    int numberOfWays(int sp, int ep, int k) {
        
        vector<vector<int>> dp(3000,vector<int> (k+1,-1));
        int cnt=0;
        
        return f(sp,ep,k,dp)%mod;
    }
};