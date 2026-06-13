class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n)    return n;

        int i=0,j=0,ans=0,zc=0;
        
        while(j<n){
            if(nums[j] == 0)zc++;

            while(zc>k){
                if(nums[i] == 0)
                    zc--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};