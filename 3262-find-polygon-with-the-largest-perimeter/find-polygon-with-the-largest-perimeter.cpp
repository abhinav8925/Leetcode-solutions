class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        if(n==3){
            if((nums[0] + nums[1])>nums[2])
                return (nums[0] + nums[1] + nums[2]);
            return -1;

        }
        

        
        long long sum = nums[0]+nums[1],ans=0;
        for(int i=2;i<n;i++){
            if(sum>nums[i]){
                ans = sum+nums[i];
            }
            sum+=nums[i];
        }
        return ans==0?-1:ans;
    }
};