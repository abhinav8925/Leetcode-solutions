// problem Link ->  https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int N) {
     long long int s=0,e=N-1,ans=-1;
     if(N==0 || N==1)
        return N;
     while(s<=e)
     {
         long long mid=(s+e)/2;

         if(mid*mid==N)
         {
             ans=mid;
             break;
         }
         else if(mid*mid>N)
            e=mid-1;
         else if(mid*mid<N)
         {
             ans=mid;
             s=mid+1;
         }
     }
     return ans;
    }
};
