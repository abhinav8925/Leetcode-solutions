class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,cnt=0;
        map<int,int> mp;
        for(int i:nums){
            cnt+=i;
            if(cnt == goal)
                ans++;
            
            if(mp.find(cnt-goal)!=mp.end())
                ans+=mp[cnt-goal];
            
            mp[cnt]++;
        }

        return ans;
    }
};