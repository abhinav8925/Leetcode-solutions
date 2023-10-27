// Problem Link -> https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:

    int eac(string s, int i, int j) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    return j - i - 1;
}

string longestPalindrome(string s) {
    int start = 0, end = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        int len1 = eac(s, i, i + 1);
        int len2 = eac(s, i, i);
        int len = max(len1, len2);
        
        if (len > (end - start)) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    
    return s.substr(start, end - start + 1);
}

};