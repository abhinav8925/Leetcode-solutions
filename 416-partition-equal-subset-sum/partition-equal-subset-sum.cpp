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
        // vector<vector<int>> dp(n,vector<int> (tar+1,-1));
        // return f(n-1,nums,tar,dp);
        vector<vector<bool>> dp(n,vector<bool> (tar+1,false));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        if(nums[0] <= tar)
            dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int temp=1;temp<=tar;temp++){
                bool not_take = dp[i-1][temp];
                bool take = false;
                if(nums[i] <= temp)
                    take = dp[i-1][temp-nums[i]];
                
                dp[i][temp] = take | not_take;
            }
        }

        return dp[n-1][tar];

    }
};