class Solution {
public:
    bool detectCapitalUse(string s) {
        int n=s.size();
        int cnts=0;
        int cntc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>=65 && s[i]<=90)
                cntc++;
            else if(s[i]>=97 && s[i]<=122)
                cnts++;
        }
        if(cntc==n || cnts==n)
            return true;
        else if(cntc==1 && s[0]>=65 && s[0]<=90)
            return true;
        else
            return false;
    }
};
