// Problem Link -> https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string k=s;
        for(int i=0;i<indices.size();i++)
        {
            k[indices[i]]=s[i];
        }
        return k;
    }
};
