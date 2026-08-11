class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        int sum=0,ans=0;
        mp[0] = -1;

        int cz=0,co=0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0)    cz+=1;
            else                co+=1;

            if(mp.find(co-cz) != mp.end()){
                ans = max(ans,i-mp[co-cz]);
            }
            else
                mp[co-cz] = i;
        }

        return ans;
    }
};