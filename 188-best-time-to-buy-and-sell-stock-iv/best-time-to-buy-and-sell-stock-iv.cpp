class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp){
        if(ind == arr.size() || cap == 0)
            return 0;
        
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0;
        if(buy){
            profit = max(
                        -arr[ind] + f(ind+1,0,cap,arr,dp),
                        0 + f(ind+1,1,cap,arr,dp));
        }else{
            profit = max(
                    arr[ind] + f(ind+1,1,cap-1,arr,dp),
                    0 + f(ind+1,0,cap,arr,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return f(0,1,k,arr,dp);

    }
};