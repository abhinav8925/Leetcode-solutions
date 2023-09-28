// Problem Link -> https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return 1;
        if(nums[0] == 0)
            return 0;

        int jp = 1;
        int sp = nums[0];
        int rng = nums[0];

        for(int i=1;i<n;i++){
            if(i == n-1)
                return 1;
            
            rng = max(rng,i+nums[i]);
            sp--;

            if(sp == 0){
                jp++;

                if(rng <= i)
                    return 0;
                
                sp = rng-i;
            }
        }

        return 0;

    }
};