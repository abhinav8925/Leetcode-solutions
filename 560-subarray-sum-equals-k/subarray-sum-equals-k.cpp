class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        map<int,int> mp;
        mp[0]=1;
        int i=0,j=0,sum=0,ans=0;

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