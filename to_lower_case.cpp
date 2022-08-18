// Date -> 18th August 2022
// Code by -> Abhinav Anand

// Problem Link -> https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string s) {
        for(auto
            i=0;i<s.size();i++)
                s[i]=tolower(s[i]);
        return s;
    }
};