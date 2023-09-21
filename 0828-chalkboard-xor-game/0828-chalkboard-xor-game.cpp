// Problem Link -> https://leetcode.com/problems/chalkboard-xor-game/

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        
        int xr=0;

        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }

        if(xr==0 || nums.size()%2==0)
            return 1;
        
        return 0;
    }
};