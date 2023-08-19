// Problem Link -> https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {

        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int> mp(26,0);
            for(int j=i;j<n;j++){         
                    mp[s[j]-'a']++;
                    int mn=1e9,mx=-1;
                    for(int i=0;i<26;i++){
                        mx=max(mx,mp[i]);
                        if(mp[i]>=1)
                            mn=min(mn,mp[i]);
                    }

                    res+=(mx-mn);
                
            }
        }

        return res;
        
    }
};
