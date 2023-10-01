// Problem Link -> https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& a) {

        int n = a.size();
        vector<int> pref(n,0),suff(n,0);

        int mx=a[0];
        for(int i=0;i<n;i++){
            if(a[i]<=mx){
                pref[i]=mx;
            }
            else{
                pref[i]=a[i];
                mx=a[i];
            }
        }
        mx=a[n-1];
        for(int i=n-1;i>=0;i--){
            if(a[i]<=mx){
                suff[i]=mx;
            }
            else{
                suff[i]=a[i];
                mx=a[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(min(pref[i],suff[i]) - a[i]);
        }

        return ans;
        
    }
};