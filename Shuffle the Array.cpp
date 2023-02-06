/*
  JAI SHREE KRISHNA
  
  Date -> 6th February 2023
  Code By -> Abhinav Anand
  
  Problem Link -> https://leetcode.com/problems/shuffle-the-array/
 
*/


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int k=2*n;
        for(int i=0,j=n;i<n;i++,j++)
        {
            v.push_back(nums[i]);
            v.push_back(nums[j]);
        }
        return v;
    }
};
