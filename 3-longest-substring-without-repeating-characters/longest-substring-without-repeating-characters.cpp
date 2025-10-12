class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0,mx=0;
        map<char,int> mp;

        for(;j<n;j++){
            while(mp.find(s[j])!=mp.end()){
                mp[s[i]]--;

                if(mp[s[i]] == 0)   mp.erase(s[i]);
                i++;
            }

            mp[s[j]]++;
            mx = max(mx,j-i+1);
        }

        return mx;
    }
};