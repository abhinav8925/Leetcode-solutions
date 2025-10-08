class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double cnt = 0;
        int n = nums.size();
         for (int i = 0;i<k;i++){
            cnt += nums[i];
         } 
         double ans = cnt;
        
        int j=0;
         for(int i=k;i<n;i++){
            cnt-=nums[j++];
            cnt+=nums[i];
            ans = max(ans, cnt);
         }

         return ans/k;
         
        }
};