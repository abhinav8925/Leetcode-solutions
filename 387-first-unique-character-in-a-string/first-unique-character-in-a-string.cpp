class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        vector<int> freq(26,-2);
        for(int i=0;i<n;i++){
            int idx = s[i]- 'a';

            if(freq[idx] == -2){
                freq[idx] = i;
            }
            else if(freq[idx] >= 0)
                freq[idx]= -1;
        }

        int ans = INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i] >-1){
                ans = min(ans,freq[i]);
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};