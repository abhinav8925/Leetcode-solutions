// Problem Link -> https://leetcode.com/problems/optimal-partition-of-string/

class Solution {
public:
    int partitionString(string st) {
        
        int ans=1;
        set<char> s;
        for(auto c: st){
            if(s.find(c)!=s.end()){
                s.clear();
                ans++;
            }
            
                s.insert(c);
            
        }
        return ans;
    }
};