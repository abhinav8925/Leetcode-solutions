class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        int ans=0;
        for(auto it:mp){
            if(it.second<=1)
                return -1;
            if(it.second%3==0)
                ans+=(it.second/3);
            else if(it.second%3==1)
                ans+=(it.second/3)-1 + 2;
            else
                ans+=(it.second/3)  +1;
                
        }
        return ans;
    }
};