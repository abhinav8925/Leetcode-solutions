class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> mp,mp2;

        for(int i=0;i<s.size();i++){
            char a = s[i];
            char b = t[i];

            if(mp.find(a) != mp.end()){
                if(mp[a] != b)
                    return false;
            }else{
                if(mp2.find(b) != mp2.end())
                    return false;
                mp[a] = b;
                mp2[b] = a;
            }
        }
        return true;
    }
};