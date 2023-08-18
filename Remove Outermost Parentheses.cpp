// Problem Link -> https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        
        int n=s.size();
        string ans="";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0)
                    ans+=s[i];
                
                cnt++;
            }
            else{
                if(s[i]==')'){
                    cnt--;
                    if(cnt>0)
                        ans+=s[i];
                }
            }
            
        }


        return ans;
    }
};
