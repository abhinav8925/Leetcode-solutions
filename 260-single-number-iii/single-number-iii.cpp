// Problem Link -> https://leetcode.com/problems/single-number-iii/

#define ll long long int

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        ll xr = 0;
        for(int i=0;i<nums.size();i++)
            xr^=nums[i];
        
        ll bit =  (xr & (xr-1))^xr;

        int a=0,b=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] & bit)
                a = a^nums[i];
            else
                b=b^nums[i];
        }

        return {a,b};

        

    }
};