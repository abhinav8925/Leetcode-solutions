class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int a=min(w1.size(),w2.size());

        string k;
        for(int i=0;i<a;i++)
        {
            k+=w1[i];
            k+=w2[i];
        }
        if(a==w1.size())
        {
            for(int i=a;i<w2.size();i++)
                k+=w2[i];
        }
        else if(a==w2.size())
        {
            for(int i=a;i<w1.size();i++)
                k+=w1[i];
        }
        return k;
    }
};
