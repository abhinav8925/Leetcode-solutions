// Problem Link -> https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double solve(double x,long n){
        double ans=1;
        while(n>0){
            int check=n&1;
            if(check)
                ans=ans*x;
            
            x=x*x;
            n>>=1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(x==1)    
            return 1;
        
        double ans=solve(x,abs(n));
        if(n<0)
            return 1/ans;
        return ans;
    }
};
