// class Solution {
// public:
//     int f(int ind, int prev, vector<int> &nums,  vector<vector<int>> &dp){
//         if(ind == nums.size())
//             return 0;
        
//         if(dp[ind][prev+1] != -1)
//             return dp[ind][prev+1];
        
//         int ntake = 0 + f(ind+1,prev,nums,dp);
//         int take = 0;

//         if(prev == -1 || nums[ind] > nums[prev]){
//             take = 1 + f(ind+1,ind,nums,dp);
//         }

//         return dp[ind][prev+1] = max(take,ntake);

//     }
//     int f2(int ind, int prev,int mx, vector<int> &temp, vector<int> &nums){
//         if(ind == nums.size()){
//             if(temp.size() == mx)
//                 return 1;

//             return 0;
//         }
        
//         int ntake =  f2(ind+1,prev,mx, temp,nums);
//         int take = 0;

//         if(prev == -1 || nums[ind] > nums[prev]){
//             temp.push_back(nums[ind]);
//             take =  f2(ind+1,ind,mx,temp,nums);
//             temp.pop_back();
//         }

//         return take+ntake;

//     }
//     int findNumberOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         int mx = f(0,-1,nums,dp);
//         vector<int> temp;
//         return f2(0,-1,mx,temp,nums);
//     }
// };


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> len(n, 1);
        vector<int> cnt(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {

                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int longest = 0;
        for (int x : len) {
            longest = max(longest, x);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == longest) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};
