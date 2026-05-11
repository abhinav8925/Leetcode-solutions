class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(),1),ans2(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            ans[i] = ans[i-1]*nums[i-1];
        }

        
        for(int i=nums.size()-2;i>=0;i--){
            ans2[i] = ans2[i+1]*nums[i+1];
        }

        for(int i=0;i<nums.size();i++){
            nums[i] = ans[i]*ans2[i];
        }

        return nums;
    }
};