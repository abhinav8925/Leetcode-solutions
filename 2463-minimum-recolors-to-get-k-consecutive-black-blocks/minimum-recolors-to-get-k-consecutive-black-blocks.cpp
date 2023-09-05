// Problem Link -> https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string s, int k) {
        
        int ans=INT_MAX;
        int n=s.size();
        int i=0;
        while(i<=n-k){
            int cnt=0;
            for(int j=i;j<i+k;j++){
                if(s[j]=='W')
                    cnt++;
            }
            ans=min(ans,cnt);
            i++;
        }   

        return ans;
        
    }
};