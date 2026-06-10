class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i=0,j=0,cnt=0,sum=0,z=0;

        while(j<n){
            sum+=nums[j];
           
                while(i<j && (nums[i]==0 || sum>goal)){
                    if(nums[i] == 0)    z++;
                    else    z=0;

                    sum-=nums[i];
                    i++;

                }
            
            if(sum == goal) cnt+=1+z;
            
            j++;
        }
        
        return cnt;
    }
};