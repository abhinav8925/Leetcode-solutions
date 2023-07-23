// Problem Link -> https://leetcode.com/contest/weekly-contest-355/problems/split-strings-by-separator/

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& s, char sp) {
        vector<string> v;
        int n=s.size();
        for(int i=0;i<n;i++){
            string a=s[i],ans="";
            for(int j=0;j<a.size();j++){
                if(a[j]!=sp)
                    ans+=a[j];
                else if(a[j]==sp && ans.size()>0){
                     v.push_back(ans);
                     ans="";
                }
            }
            if(ans.size()>0)
                v.push_back(ans);
           
        }
        return v;
    }
};
