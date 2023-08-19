// Problem Link -> https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int ,int> m;

        for(int x:nums)
            m[x]++;
        
        sort(nums.begin(),nums.end(), [&](int a, int b){
            return m[a]!=m[b] ? m[a]<m[b]:a>b;
        });

        return nums;
    }
};
