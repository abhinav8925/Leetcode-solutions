// Problem Link -> https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i]=-1;
            
        mp[0]=0;
        int sum=0,len=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(mp.find(sum)!=mp.end()){
                len = max(len,i+1-mp[sum]);
            }
            else{
                mp[sum]=i+1;
            }
        }

        return len;
        
    }
};