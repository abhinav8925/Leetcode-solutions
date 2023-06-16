// Problem Link -> https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i+=2){
            int k=nums[i];
            int l=nums[i+1];
            while(k--){
                v.push_back(l);
            }
        }
        return v;
    }
};
