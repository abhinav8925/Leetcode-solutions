class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntp=0;
        int cntn=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                cntp++;
            else if(nums[i]<0)
                cntn++;
                
        }
        return max(cntp,cntn);
        
    }
};