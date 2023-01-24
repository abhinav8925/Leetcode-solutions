class Solution {
public:
    bool isPalindrome(int x) {
        long long  n=x;
        long long  ans=0;
        while(n>0)
        {
            ans=ans*10+(n%10);
            n/=10;
        }
        if(ans==x)
                return true;
        else
                return false;
    }
};
