class Solution {
public:

    bool f(int mid, int n, vector<int> &nums,int h){
        
        long long cnt=0;
        for(int i=0;i<n;i++){ 
            if(cnt>h)   return false;  
            if(nums[i]>mid){
                cnt+=((nums[i]+mid-1)/mid);
            }
            else
                cnt++;
        }
        if(cnt<=h)
            return true;
        return false;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        
        int n = nums.size();

        int low = 1;
        int high=*max_element(nums.begin(),nums.end());
        int ans = high;

        while(low <= high){
            int mid = (low+high)/2;

            if(f(mid, n, nums,h)){
                ans = mid;
                high=mid-1;
            }else
                low=mid+1;
        }

        return ans;

    }
};