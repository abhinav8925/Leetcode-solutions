// problem Link -> https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string s) {
        string k="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                k+='[';
                k+='.';
                k+=']';
            }
            else
                k+=s[i];
        }
        return k;
    }
};
