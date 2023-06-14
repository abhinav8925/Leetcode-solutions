// Problem Link -> https://leetcode.com/problems/decode-xored-array/

class Solution {
public:
    vector<int> decode(vector<int>& a, int first) {
        vector<int> v;
        v.push_back(first);
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            int k=v[i]^a[i];
            v.push_back(k);
        }
        return v;
    }
};
