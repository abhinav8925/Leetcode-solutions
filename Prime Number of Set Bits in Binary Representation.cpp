// Problem Link -> https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

class Solution {
public:
    int cntd(int n){
        int vnt=0;
        while(n!=0){
            vnt++;
            n=n&(n-1);
        }
        return vnt;
    }
    bool isprime(int n){
        if(n<=1)
            return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        
        int cnt=0;
        for(int i=left;i<=right;i++){

            if(isprime(cntd(i)))
                cnt++;
        }

        return cnt;
    }
};
