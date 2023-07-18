// Problem Link -> https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            
            if(s[i]=='G')
                ans+='G';
            else if(s[i]=='(' && i+1<n && s[i+1]==')'){
                ans+='o';
                i++;
            }
            else if(i+3<n && s[i]=='(' && s[i+1]=='a'){
                ans+='a';
                ans+='l';
                i+=3;
            }
            
        }

        return ans;
    }
};
