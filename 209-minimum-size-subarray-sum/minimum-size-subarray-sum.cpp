class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int mn = INT_MAX;
        int i=0,j=0,sum=0;

        while(j<nums.size()){
            if(sum>=target){
                mn = min(mn,j-i);
                sum-=nums[i++];
            }
            else{
                sum+=nums[j++];
            }
        }

        while(sum>=target){
            mn = min(mn,j-i);
            sum-=nums[i++];
        }

        return mn!=INT_MAX ? mn: 0;
    }
};