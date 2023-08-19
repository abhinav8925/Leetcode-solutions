// Problem Link -> https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        unordered_map<char,int> m;

        for(char c:s)
            m[c]++;
        
        sort(s.begin(),s.end(),[&](char a,char b){
            if(m[a]!=m[b])
                return m[a]>m[b];
            return a<b;
        });
        return s;
    }
};
