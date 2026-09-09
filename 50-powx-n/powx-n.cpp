class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;

        if (N < 0) {
            x = 1.0 / x;
            N*=(-1);
        }
        while(N>0){
            if(N%2 == 1){
                ans = ans*x;
                N--;
            }else{
                x = x*x;
                N/=2;
            }
        }

        
        return ans;
    }
};