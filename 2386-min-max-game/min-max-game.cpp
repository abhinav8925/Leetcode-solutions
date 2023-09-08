// Problem Link -> https://leetcode.com/problems/min-max-game/

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
         vector<int> arr;
        int i, new_num, n;
        n = nums.size();
        while(n>1)
        {
            n = nums.size();
            for(i=0 ; i<n/2 ; i++)
            {
                if(i%2==0)
                {
                    new_num = min(nums[2*i], nums[2*i+1]);
                    arr.push_back(new_num);
                }
                else
                {
                    new_num = max(nums[2*i], nums[2*i+1]);
                    arr.push_back(new_num);
                }
            }
            nums.clear();
            nums = arr;
            arr.clear();
        }
        return nums[0];
    }
};