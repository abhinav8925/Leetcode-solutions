// Problem Link -> https://leetcode.com/problems/min-cost-climbing-stairs/?envType=daily-question&envId=2023-10-13

class Solution {
public:
    int f(int ind,vector<int> &cost,vector<int> &dp){

        if(ind <= 1){
            return cost[ind];
        }
        
        if(dp[ind] !=-1)
            return dp[ind];
        int l=0,r=0;
        if(ind>1)
            l = cost[ind] + f(ind-2,cost,dp);

        r = cost[ind] + f(ind-1,cost,dp);

        return dp[ind] =  min(l,r);
            
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int ind = n-1;

        vector<int> dp(n+1,-1);

        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};