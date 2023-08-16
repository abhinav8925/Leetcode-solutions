// Problem Link -> https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /* 
        brute force

        int val=0;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(i!=nums[i])
                {
                    val=i;
                    break;
                }
        }
        if(i>=nums.size())
        return i;
        else
            return val;

        */

        // optimal 

        int sum = 0; 
        int total = nums.size()*(nums.size() + 1)/2; 
        for (auto number : nums) { 
            sum += number; 
        }
        return total - sum;
        

    }
};
