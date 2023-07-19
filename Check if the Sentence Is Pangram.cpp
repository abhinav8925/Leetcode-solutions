// Problem  Link -> https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string s) {
        int n=s.size();
        if(s.size()<26)
            return false;
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        bool ans=true;
        for(int i=0;i<26;i++){
            if(v[i]==0){
                ans=false;
                break;
            }
        }
        if(ans)
            return true;
        return false;
    }
};
