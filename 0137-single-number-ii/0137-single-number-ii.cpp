// Problem Link -> https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        int ones = 0;
        int two = 0;

        for(int i=0;i<nums.size();i++){
            ones = (ones^nums[i]) & (~two);
            two = (two^nums[i]) & (~ones);
        }

        return ones;
    }
};