// Problem Link -> https://leetcode.com/problems/beautiful-towers-i/

#define ll long long int

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        
         int n=a.size();
        
       ll  ans=0;
        for(int i=0;i<n;i++){
            ll  sum = a[i];
            int prev=a[i];
            for(int j=i-1;j>=0;j--){
                prev = min(a[j],prev);
                sum += prev;
            }
            prev=a[i];
            for(int j=i+1;j<n;j++){
                prev = min(a[j],prev);
                sum += prev;
            }
            
            if(sum > ans) ans=sum;
        }
        
        return ans;
    }
};