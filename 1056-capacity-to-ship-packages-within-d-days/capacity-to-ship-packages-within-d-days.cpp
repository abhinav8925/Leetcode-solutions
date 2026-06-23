class Solution {
public:

    bool f(int mid, int d, vector<int> &nums, int n){
        int sum=0,ans=1;

        for(int i=0;i<n;i++){
            if(ans>d) return false;

            if(sum + nums[i] <= mid)    {
                sum+=nums[i];
                
            }
            else{
                ans++;
                sum=nums[i];
            }
        }

        
        return ans <=d ? true : false;
    }

    int shipWithinDays(vector<int>& nums, int d) {
        
        int n = nums.size();
        int high = accumulate(nums.begin(),nums.end(),0);
        int low=*max_element(nums.begin(),nums.end()),ans=INT_MAX;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(f(mid, d, nums,n)){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;

    }
};