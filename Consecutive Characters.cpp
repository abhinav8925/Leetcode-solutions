// Problem link -> https://leetcode.com/problems/consecutive-characters/description/

class Solution {
public:
    int maxPower(string s) {
        int cnt=1,mx=0;
        int n=s.size();

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                cnt++;
            else{
                mx=max(mx,cnt);
                cnt=1;
            }
        }

        return max(mx,cnt);
    }
};
