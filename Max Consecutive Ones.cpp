// Problem Link -> https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,mx=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                cnt++;
            else{
                mx=max(mx,cnt);
                cnt=0;
            }
        }
        return max(mx,cnt);
    }
};
