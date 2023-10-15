// Problem Link -> https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1));
        return dp(nums, target, 0, memo);
    }

private:
    bool dp(vector<int>& nums, int target, int idx, vector<vector<int>>& memo) {
        if (idx == nums.size()) return false;
        if (nums[idx] == target) return true;
        if (memo[idx][target] != -1) return memo[idx][target];

        int take = false;
        if (target > nums[idx]) take = dp(nums, target - nums[idx], idx + 1, memo);
        int notTake = dp(nums, target, idx + 1, memo);
        return memo[idx][target] = take || notTake;
    }
};
