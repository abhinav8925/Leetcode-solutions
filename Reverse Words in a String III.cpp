// Problem link -> https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        string ans="",word="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' ')
                word=s[i]+word;
            else if(s[i]==' '){
                // reverse(word.begin(),w.end());
                ans+=word;
                ans+=' ';
                word="";
            }
        }

        ans+=word;

        return ans;
    }
};
