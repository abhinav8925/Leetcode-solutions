// Problem Link -> 

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> left_min(n);
        left_min[0]=nums[0];
        for(int i=1;i<n;i++) left_min[i]=min(left_min[i-1],nums[i]);
        
        vector<int> right_min(n);
        right_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) right_min[i]=min(right_min[i+1],nums[i]);
            
        
        int ans=INT_MAX;
        
        for(int i=1;i<n-1;i++){
            if(nums[i]>left_min[i-1] && nums[i]>right_min[i+1]) ans=min(ans,left_min[i-1]+nums[i]+right_min[i+1]);
        }
        
        return (ans==INT_MAX ? -1:ans);
    }
};