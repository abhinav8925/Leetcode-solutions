// Problem Link -> https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool ans=false;
        int n=s.size();
        for(int i=n-1;i>=0;){
            if(s[i]==' ' && i>=0){
                i--;
                if(ans)
                    break;
            }
            else if(s[i]!=' ' && i>=0){
                cnt++;
                i--;
                ans=true;
            }
        }
        return cnt;
    }
};
