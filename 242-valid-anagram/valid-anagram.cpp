class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> a(26,0),b(26,0);
        if(s.size() != t.size())    return false;

        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++){
            b[t[i]-'a']++;
        }

        return a == b ? true: false;
    }
};