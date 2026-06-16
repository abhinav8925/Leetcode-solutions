class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i=0,j=0,ans=0,sum=0,cz=0;
        

        while(j<n){
            sum+=nums[j];

            while(i<j && (nums[i]==0 || sum>goal)){
                if(nums[i] == 1)    cz=0;
                else    cz++;

                sum-=nums[i];
                
                i++;
            }

            if(sum == goal)
                 ans+=(1+cz);

            j++;
        }
        
        return ans;
    }
};