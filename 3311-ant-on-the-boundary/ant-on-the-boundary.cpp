#include<bits/stdc++.h>


class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cntp=0,cnt=0;
        for(int i=0;i<nums.size();i++){
    
                cntp+=nums[i];
            if(cntp==0)
                cnt++;
        }   
        return cnt;
    }
};