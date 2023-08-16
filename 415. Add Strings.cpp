// Problem Link -> https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string X, string Y) {
         string ans;
       int c=0, i=X.length()-1, j = Y.length()-1;
       while(i>=0 || j>=0)
       {
           if(i>=0)
           {
               c += (X[i--]-'0');
           }
           if(j>=0)
           {
               c += (Y[j--]-'0');
           }
           
           ans += to_string(c%10);
           c /= 10;
       }
       ans += to_string(c);
       for(int k=ans.size()-1;k>0;k--)
       {
           if(ans[k]=='0')
           ans.pop_back();
           else break;
       }
       reverse(ans.begin(), ans.end());
       return ans;
   }
    
};
