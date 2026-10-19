class Solution {
public:
    int f(int ind, int end, vector<int> &cuts, 
    vector<vector<int>>& dp){
    
        if(ind > end)
            return 0;
            
        if(dp[ind][end] != -1)
            return dp[ind][end];
        
        int mn = 1e9;
        
        for(int k = ind; k<=end;k++){
            int cost = -cuts[ind-1] + cuts[end+1] + f(ind,k-1,cuts,dp) + f(k+1,end,cuts,dp);
            mn = min(mn,cost);
        }

        return dp[ind][end] = mn;

    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int n2 = cuts.size();
        
        vector<vector<int>> dp(n2,vector<int> (n2,-1));
        return f(1,n2-2,cuts,dp);
    }
};