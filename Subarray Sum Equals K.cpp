// Problem Link -> https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        long long sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        int len=0,n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(m.find(sum-k)!=m.end()){
               cnt+=m[sum-k];
            }
            
                m[sum]++;
            
        }

        return cnt;
