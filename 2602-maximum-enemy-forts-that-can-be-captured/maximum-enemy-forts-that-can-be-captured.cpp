// Problem Link -> https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/

class Solution {
public:
    int captureForts(vector<int>& a) {
        
        int i=0,j=0, ans=0;

        int n= a.size();

        if(n==0 || n==1)
            return 0;
        
        while(j<n){
            if(a[i]==0)
                i++;
            if((a[i]==1 && a[j]==-1) or (a[i]==-1 && a[j]==1)){
                ans=max(ans,j-i-1);
                i=j;
            }
            if(a[i]==a[j])
                i=j;
            
            j++;
        }

        return ans;

    }
};