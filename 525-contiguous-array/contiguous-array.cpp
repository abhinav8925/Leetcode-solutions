class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                sum--;
            else
                sum++;
            
            if(mp.find(sum)!=mp.end())
                ans = max(ans,i-mp[sum]+1);
            else
                mp[sum]=i+1;
        }
        return ans;
    }
};