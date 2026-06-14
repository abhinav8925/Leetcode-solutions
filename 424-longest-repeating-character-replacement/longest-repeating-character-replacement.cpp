class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0,ans=0,mc=0;
        map<char,int> mp;

        while(j<n){
            mp[s[j]]++;
            mc = max(mc, mp[s[j]]);
            while(i<n && (j-i+1-mc) > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0)   mp.erase(s[i]);

                i++;
            }
            ans = max(ans,j-i+1);
            
            j++;
        }

        return ans;
    }
};