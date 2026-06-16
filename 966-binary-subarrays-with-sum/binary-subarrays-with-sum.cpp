class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i=0,j=0,ans=0,sum=0;
        map<int,int> mp;
        mp[0]=1;

        while(j<n){
            sum+=nums[j];
            if(mp.find(sum-goal)!=mp.end())
                ans+=mp[sum-goal];
            
            mp[sum]++;
            j++;
        }

        
        return ans;
    }
};