// Problem Link -> https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/

class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int i=0,j=0;
        int mx=0,cnt=0;
        int n=s.size();
        for(int i=0;i<n;)
        {
            if(s[i][j]==' ')
            {
                cnt++;
                j++;
            }
            else if(s[i][j]=='\0')
            {
                i++;
                j=0;
                mx=max(mx,cnt);
                cnt=0;
            }
            j++;
        }
        return mx+1;
    }
};
