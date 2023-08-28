// Problem Link -> https://leetcode.com/problems/add-binary/

// Brute Force not AC because constraints of a size()==10^4;
// class Solution {
// public:
//     string addBinary(string a, string b) {
//          long long n1=0;
//          long long  n2=0;
//          long long o=0;
//          for(int i=a.size()-1;i>=0;i--)
//          {
//              n1=(a[i]-'0')*(pow(2,o))+n1;
//              o++;
//          } 
//          o=0;
//          for(int i=b.size()-1;i>=0;i--)
//          {
//              n2=(b[i]-'0')*(pow(2,o))+n2;
//              o++;
//          } 
//         long long  ans=n1+n2;
//         long long  ans2=ans;
//         string k="";
        
//         while(ans>0)
//         {
//             k+=(ans%2)+'0';
//             ans/=2;
//         }
//         reverse(k.begin(),k.end());
//         if(ans2==0)
//             return "0";
//         return k;
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        

        string ans="";
        int carry=0;
        int i=a.size()-1,j=b.size()-1;

        while(i>=0 || j>=0){
            
            int sum=carry;
            if(i>=0)
                sum+= a[i]-'0';
            if(j>=0)
                sum+= b[j]-'0';

            i--;
            j--;

            carry = sum>1 ? 1 : 0;

            ans+=to_string(sum%2);
            

        }

        if(carry) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;


    }
};







































