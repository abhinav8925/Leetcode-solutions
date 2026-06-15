class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0,ans=0,cz=0;

        while(j<n){
            if(nums[j] == 0)    cz++;

            while(i<n && cz>1){
                if(nums[i] == 0)
                    cz--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans-1;
    }
};