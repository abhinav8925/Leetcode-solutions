class Solution {
public:
    int f(int ind, vector<int> &nums, int tar){
        if(ind == 0){
            if(tar == 0 && nums[ind] == 0)
                return 2;
            if(tar - nums[ind] == 0)
                return 1;
            if(tar + nums[ind] == 0)
                return 1;
            return 0;
        }
        int ptake = f(ind-1,nums,tar+nums[ind]);
        int ntake = f(ind-1,nums,tar-nums[ind]);

        return ptake+ntake;
    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        return f(n-1,nums,tar);
    }
};