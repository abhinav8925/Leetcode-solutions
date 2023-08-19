// Problem Link -> https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        
        int cnt=0,ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
                cnt--;
            
            ans=max(ans,cnt);
        }

        return ans;
    }
};
