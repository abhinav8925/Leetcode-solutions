class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;   
        
        
        int cnt=0;
        for(auto ch:s){
            m[ch]++;
            if(m[ch]%2!=0)
                cnt++;
            else
                cnt--;
        }

        if(cnt>1)
            return s.size()-cnt+1;
        return s.size();
        
    }
};