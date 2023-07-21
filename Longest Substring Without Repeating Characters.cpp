// Problem Link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int n = s.size();
        int cnt = 0, mx = 0;
        
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i; 
                cnt++;
            } else {
                mx = max(cnt, mx);
                i = mp[s[i]]; 
                mp.clear();   
                cnt = 0;     
            }
        }

        return max(cnt, mx);
        }
};
