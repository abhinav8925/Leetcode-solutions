// Problem Link -> https://leetcode.com/contest/weekly-contest-349/problems/neither-minimum-nor-maximum/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn=101,mx=-1;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=mn && nums[i]!=mx){
                return nums[i];
            }
        }
        return -1;
    }
};
