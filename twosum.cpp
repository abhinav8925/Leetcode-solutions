class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> b(2);
   
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
        if(nums[i]+nums[j]==target)
            {
                b[0]=i;
                b[1]=j;
                break;
            }
        }
    }
    return b;
    }
    
};
