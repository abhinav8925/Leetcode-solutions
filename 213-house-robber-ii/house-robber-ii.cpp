class Solution {
public:
    int f(int ind, vector<int> &nums, int sz,vector<int> &dp){
        if(ind > sz)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int take = nums[ind];
        if(ind+1 < sz)
            take +=  f(ind+2,nums,sz,dp);
        int not_take = 0 + f(ind+1,nums,sz,dp);

        return dp[ind] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);

        vector<int> dp1(n,-1),dp2(n,-1);

        int a = f(0,nums,n-2,dp1);
        int b = f(1,nums,n-1,dp2);
        return max(a,b);
    }
};