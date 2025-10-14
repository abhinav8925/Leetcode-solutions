class Solution {
public:

    int f(string s, int k){
        if(s.size() == 0)
            return 0;
        
        map<char,int> mp;
        for(char c:s)   mp[c]++;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]] < k){
                int l = f(s.substr(0,i),k);
                int r = f(s.substr(i+1), k);


                return max(l,r);
                
            }
        }
        return s.size();
    }
    int longestSubstring(string s, int k) {
        return f(s,k);

    }
};