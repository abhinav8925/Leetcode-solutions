class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

     int p = 0;
     map<int,int> mp;
     mp[0]=-1;

     for(int i=0;i<nums.size();i++){
        p = (p+nums[i])%k;
        if(mp.find(p)!=mp.end()){
            if(i-mp[p]>1)
                return 1;
        }
        else{
            mp[p]=i;
        }
     }
     return false;

    }
};