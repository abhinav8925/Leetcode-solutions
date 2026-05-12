class Solution {
public:
    int lengthOfLongestSubstring(string s) {

     map<char,int> mp;
     int n = s.size();
     int i=0,left=0,ans=0;

     while(i<n){
        while(mp.find(s[i]) != mp.end()){
                mp[s[left]]--;
                if(mp[s[left]]==0)
                    mp.erase(s[left]);

                left++;
            }
            ans = max(ans,(i-left)+1);
            mp[s[i]]++;
            i++;
        }
    
     return ans;
    }
};