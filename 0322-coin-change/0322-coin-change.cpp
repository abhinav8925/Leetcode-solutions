// Problem Link -> https://leetcode.com/problems/coin-change/

class Solution {
public:
    int rec(int ind,vector<int>& coins, int amt,vector<vector<int>>& dp){
        if(ind==0){
            if(amt%coins[0]==0){ 
                return amt/coins[0];
            }
            return 1e9;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int nt=rec(ind-1,coins,amt,dp);
        int t=1e9;
        if(coins[ind]<=amt){
            t=1+rec(ind,coins,amt-coins[ind],dp);
        }
        return dp[ind][amt]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= rec(n-1,coins,amount,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};