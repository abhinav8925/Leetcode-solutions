class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)
            return 0;
        

        sort(begin(nums),end(nums));

        int ans=INT_MAX;
        for(int left=0,right=nums.size()-4;left<4;left++,right++)
            ans = min(ans,nums[right]-nums[left]);
        

        return ans;

    }
};