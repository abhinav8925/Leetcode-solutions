// Problem Link -> https://leetcode.com/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();

        for(int i=0;i<n;i+=(2*k)){

           int f=i;
           int sn=i+k-1;

           if(sn>=s.size()-1)
                sn=s.size()-1;
           for(;f<sn;f++,sn--)
                swap(s[f],s[sn]);

        }

        return s;
    }
};
