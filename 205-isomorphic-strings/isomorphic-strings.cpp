// Problem Link -> https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> mpp;
        set<char> st;
        int n=s.size();

        

        for(int i=0;i<n;i++){
            
            if(mpp.count(s[i])==0 && st.count(t[i])==0){
                    mpp[s[i]]=t[i];
                    st.insert(t[i]);
            }
            else if(mpp.count(s[i])==0 && st.count(t[i]))
                return false;          
            else if(mpp[s[i]] !=t[i])
                return false;

            
        }

        return true;
    }
};