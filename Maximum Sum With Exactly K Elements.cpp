
// Problem Link -> https://leetcode.com/contest/biweekly-contest-103/problems/maximum-sum-with-exactly-k-elements/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mx=nums[nums.size()-1];
        int ans=mx;
        for(int i=1;i<k;i++)
        {
            ans=ans+(mx+i);
        }
        return ans;
        
    }
};
