// Problem Link -> https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string k="";
        for(int i=0;i<n;i++)
        {
            if(s[i]>=65 && s[i]<=90)
                {
                    s[i]=tolower(s[i]);
                    k+=s[i];
                }
            else if(s[i]>=97 && s[i]<=122)
                {
                    s[i]=tolower(s[i]);
                    k+=s[i];
                }
            else if(s[i]>=48 && s[i]<=57)
                {
                    k+=s[i];
                }
        }

        for(int i=0,j=k.size()-1;i<j;i++,j--)
        {
            if(k[i]!=k[j])
                return false;
        }
        return true;

    }
};
