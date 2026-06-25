class Solution {
public:

    bool f(int m, int k, vector<int> &nums){
        int prev = nums[0];
        int n = nums.size(),cnt=1;

        for(int i=1;i<n;i++){

            if(nums[i] - prev >= m){
                prev = nums[i];
                cnt++;
            }else
                continue;
            
        }

        return cnt >= k? true:false;
    }
    int maxDistance(vector<int>& nums, int k) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int l = 1,h=nums[n-1] - nums[0];
        int ans = 0;

        while(l<=h){
            int m = l + (h-l)/2;

            if(!(f(m,k,nums))){
                
                h = m-1;
            }else{
                ans=m;
                l = m+1;
            }
        }

        return ans;
    }
};