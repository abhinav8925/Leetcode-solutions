class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        long long int v=-1;
        bool answ=true;

        if(x<0)
            {
                answ=false;
                x=x*v;
            }
        
        while(x!=0)
        {
            int k=x%10;
            ans=ans*10+k;
            x/=10;
        }
        if(ans>=INT_MIN && ans<=INT_MAX)
        {
            if(answ==true)   return ans;
            else    return ans*v;
        }
        else
            return 0;
    }
};
