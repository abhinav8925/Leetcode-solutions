class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int cnt=0;
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
            ans^=nums[i];
        
        while(ans || k){
            if((ans%2)!=(k%2))
                cnt++;
            ans/=2;
            k/=2;
        }

        return cnt;
    }
};