// Problem Link -> https://leetcode.com/contest/weekly-contest-348/problems/minimize-string-length/

class Solution {
public:
    int minimizedStringLength(string s) {
       map<char,int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
    
        int cnt=0;
        for(auto &it:m){
            if(it.second>=1)    
                cnt++;
        }
        
        return cnt;
    }
};
