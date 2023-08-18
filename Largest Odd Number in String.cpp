// Problem Link -> https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        

        int i=0,n=num.size();

        for(i=n-1;i>=0;i--){
            if( (num[i]-'0') &1)
                break;
        }

        string ans="";

        for(int j=0;j<=i;j++)
            ans+=num[j];
        
        return ans;
    }
};
