// Problem Link -> https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

       if(str1+str2 != str2+str1)
            return "";
        

        int k= __gcd(str1.size(),str2.size());
    

        string ans="";
        
        for(int i=0;i<k;i++)
            ans+=str1[i];
        
        return ans;
        
    }
};