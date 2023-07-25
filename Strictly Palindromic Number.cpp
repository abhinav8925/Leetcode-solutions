// Problem Link -> https://leetcode.com/problems/strictly-palindromic-number/

class Solution {
public:
    bool ispal(string s){
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    bool check(int n,int a){
        string s="";
        while(n!=0){
            s+=to_string(n%a);
            n/=a;
        }
        cout << s << " ";
        return ispal(s);
    }
    bool isStrictlyPalindromic(int n) {
        // return false;

        for(int i=2;i<=n-2;i++){
            int temp=n;
            if(!check(temp,i))
                return false;
        }
        return true;
    }
};
