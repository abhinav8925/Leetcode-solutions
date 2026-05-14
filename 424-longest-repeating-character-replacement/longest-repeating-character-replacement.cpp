class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k == s.size())
            return k;
        
        int mx_f = 0;
        map<char,int> mp;
        int ans=0,i=0,left=0;

        while(i<s.size()){
            
                mp[s[i]]++;
                mx_f = max(mx_f,mp[s[i]]);
            
            while((i-left+1)-mx_f>k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, i-left+1);
            i++;
        }
        return ans;
    }
};