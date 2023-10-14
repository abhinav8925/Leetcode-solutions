// Problem Link -> https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:


    int f(int curi,int previ, vector<vector<int>> &dp,vector<int> &nums){

        if(curi==nums.size())
            return 0;
        
        if(dp[curi][previ+1] !=-1)
            return dp[curi][previ+1];
        
        int take = 0;
        if(previ == -1 || nums[curi] > nums[previ])
            take = 1+ f(curi+1,curi,dp,nums);
        int nottake = f(curi+1,previ,dp,nums);

        return dp[curi][previ+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        

        int curi=0;
        int previ=-1;
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));

        return f(curi,previ,dp,nums);
    }
};