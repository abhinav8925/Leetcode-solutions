class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]^=nums[i+1];
        }
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                    k=nums[i];
        }
        return k;
    }
};
