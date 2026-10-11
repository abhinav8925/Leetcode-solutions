class Solution {
public:
    bool f(int ind, vector<int> &nums, int tar,vector<vector<int>> &dp){
        if(tar == 0)
            return true;
        
        if(ind == 0)
            return nums[0] == tar;
        
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        bool not_take = f(ind-1,nums,tar,dp);
        bool take = false;
        if(nums[ind]<=tar)
            take = f(ind-1,nums,tar-nums[ind],dp);
        
        return dp[ind][tar] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        
        if(sum%2 != 0)
            return false;
        
        int tar = sum/2;
        vector<vector<int>> dp(n,vector<int> (tar+1,-1));
        return f(n-1,nums,tar,dp);


    }
};