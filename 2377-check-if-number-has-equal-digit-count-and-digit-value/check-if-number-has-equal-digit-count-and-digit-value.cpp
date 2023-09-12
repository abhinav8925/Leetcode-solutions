// Problem Link -> https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/

class Solution {
public:
    bool digitCount(string s) {
        unordered_map<char, int>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        for(int i=0; i<s.size(); i++)
        {
            char c=i+'0';
            if(mp[c]!=s[i]-'0')
                return false;
        }
        
        return true;
    }
};