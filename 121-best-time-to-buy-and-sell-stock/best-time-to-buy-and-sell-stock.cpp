class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mn = INT_MAX;

        for(int i=0;i<n;i++){
            mn = min(mn,nums[i]);
            ans = max(ans,abs(mn-nums[i]));
        }

        return ans;
    }
};