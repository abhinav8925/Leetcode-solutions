class Solution {
public:
    int missingNumber(vector<int>& nums) {
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


    }
};
