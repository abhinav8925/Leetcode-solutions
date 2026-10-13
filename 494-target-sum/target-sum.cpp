
class Solution {
public:
    int f(int ind, vector<int>& nums, int tar,
          vector<vector<int>>& dp, int offset) {
        if (tar < -offset || tar > offset)
            return 0;

        if (ind == 0) {
            if (tar == 0 && nums[0] == 0) return 2;
            if (tar == nums[0] || tar == -nums[0]) return 1;
            return 0;
        }

        int col = tar + offset;
        if (dp[ind][col] != -1)
            return dp[ind][col];

        int plus = f(ind - 1, nums, tar - nums[ind], dp, offset);
        int minus = f(ind - 1, nums, tar + nums[ind], dp, offset);

        return dp[ind][col] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0;

        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        // return f(n - 1, nums, target, dp, total);
                int offset = total;
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, 0));

        dp[0][offset + nums[0]]++;
        dp[0][offset - nums[0]]++;

        for (int i = 1; i < n; i++) {
            for (int s = -total; s <= total; s++) {
                int ways = dp[i - 1][s + offset];
                if (ways == 0) continue;

                dp[i][s + nums[i] + offset] += ways;
                dp[i][s - nums[i] + offset] += ways;
            }
        }

        return dp[n - 1][target + offset];
    }
};
