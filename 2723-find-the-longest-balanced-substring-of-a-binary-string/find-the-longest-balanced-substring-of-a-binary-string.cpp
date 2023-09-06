// Problem Link -> https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int i=0,ans=0;
        int n=s.size();

        while(i<n){
            int z=0,o=0;

            while(i<n && s[i]=='0'){
                if(s[i]=='0'){
                    z++;
                    i++;
                }
                else
                    break;
            }
            while(i<n && s[i]=='1'){
                if(s[i]=='1'){
                    o++;
                    i++;
                }
                else    
                    break;
            }
            if(z==o)
                ans=max(ans,z+o);
            else
                ans=max(ans,2*min(z,o));
        }

        return ans;
    }
};