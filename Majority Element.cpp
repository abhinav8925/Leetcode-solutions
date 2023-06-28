// Problem Link-> https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        n=n/2;
        int ans=0,ans2=0;
        for(auto &it:m){
            if(it.second>n)
                return it.first;
        }
        
        return 0;
    }
};
