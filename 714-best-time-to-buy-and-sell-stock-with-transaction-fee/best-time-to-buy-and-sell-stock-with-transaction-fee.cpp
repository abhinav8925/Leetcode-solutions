class Solution {
public:
    int f(int ind, int buy, int fee, vector<int> &arr, vector<vector<int>> &dp){
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy){
            profit = max(
                    -arr[ind] + f(ind+1,0,fee,arr,dp),
                    0 + f(ind+1,1,fee,arr,dp));
        }else{
            profit = max(
                    (arr[ind] -fee) + f(ind+1,1,fee,arr,dp),
                    0 + f(ind+1,0,fee,arr,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,fee,arr,dp);
    }
};