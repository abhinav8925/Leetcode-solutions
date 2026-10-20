#include<bits/stdc++.h>
class Solution {
public:
    
    int f(int ind, vector<int> &arr, int k,vector<int> &dp){
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int mx = 0,len=0,ans=0;
        int oo = min((int)arr.size(), k + ind);
        for(int j = ind;j<oo;j++){
            len++;
            mx = max(mx,arr[j]);
            int sum = len*mx + f(j+1,arr,k,dp);
            ans = max(ans,sum);
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
    }
};