class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        
        int prod = 1,left=0,right=0,cnt=0;
        if(k<=1)    
            return 0;
        int n = a.size();

        while(right<n){
            prod*=a[right];
            
            while(prod>=k){
                prod/=a[left];
                left++;
            }
            cnt+= (right-left)+1;
            right++;
        }

        return cnt;
    }
};