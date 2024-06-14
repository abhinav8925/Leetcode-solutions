class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(begin(nums),end(nums));
        int prev=-1,ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]<=prev){
                ans+=(prev+1-nums[i]);
                nums[i]=prev+1;
                
            }

            prev= nums[i];
            
        }

        return ans;
    }
};