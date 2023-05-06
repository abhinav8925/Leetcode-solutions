
// Problem Link -> https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& s) {
        int x=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string l=s[i];
            if(l[0]=='+' || l[2]=='+')
                x++;
            else
                x--;
        }
        return x;
    }
};
