class Solution {
public:
    // int f(int ind, vector<int> &nums, int sz,vector<int> &dp){
    //     if(ind > sz)
    //         return 0;
        
    //     if(dp[ind] != -1)
    //         return dp[ind];
        
    //     int take = nums[ind];
    //     if(ind+1 < sz)
    //         take +=  f(ind+2,nums,sz,dp);
    //     int not_take = 0 + f(ind+1,nums,sz,dp);

    //     return dp[ind] = max(take,not_take);
    // }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);

        // int a = f(0,nums,n-2,dp1);
        // int b = f(1,nums,n-1,dp2);

        vector<int> dp1(n,-1),dp2(n,-1);
        dp1[0] = nums[0];

        for(int i=1;i<=n-2;i++){
            int take = nums[i];
            if(i>1)
                take+= dp1[i-2];
            int not_take = dp1[i-1];
            dp1[i] = max(take,not_take);
        }

        dp2[1] = nums[1];
        dp2[0] = 0;
        for(int i=2;i<=n-1;i++){
            int take = nums[i];
            if(i>1)
                take += dp2[i-2];
            
            int not_take = dp2[i-1];
            dp2[i] = max(take,not_take);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};