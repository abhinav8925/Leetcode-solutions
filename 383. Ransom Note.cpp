// Problem Link -> https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char,int> mp;
        for(int i=0;i<m.size();i++)
            mp[m[i]]++;
        
        for(int i=0;i<r.size();i++){
            if(mp.find(r[i])!=mp.end()){
                mp[r[i]]--;
                if(mp[r[i]] == 0)
                    mp.erase(r[i]);
            }
            else
                return 0;
            
        }

        return 1;
    }
};
