class Solution {
public:

    int f(int cur,int prev,vector<int> &nums, vector<vector<int>> &dp){
        
        if(cur>=nums.size())
            return 0;
        
        if(dp[cur][prev+1]!=-1)
            return dp[cur][prev+1];
        
        int take = 0;
        if(prev==-1 || nums[cur]>nums[prev])
            take = f(cur+1,cur,nums,dp)+1;
        int ntake = f(cur+1,prev,nums,dp);

        return dp[cur][prev+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {

        int  n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));

        int cur=0,prev=-1;
        return f(cur,prev,nums,dp);    
    }
};