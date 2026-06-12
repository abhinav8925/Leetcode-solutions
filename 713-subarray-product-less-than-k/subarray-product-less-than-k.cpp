class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0,j=0,ans=0,len=0;
        long long cnt=1;

        if(k == 0 || k== 1)  return 0;

        while(j<n){
            cnt*=nums[j];
            while(i<n && cnt>=k){
                cnt/=nums[i];
                i++;
            }
            // len = max(j-i+1,len);
            ans+=(j-i+1);
            j++;
        }

        return ans;
    }
};