class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();

        int cntv=0,ans=0;

        for(int i=0;i<k;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i]=='u'){
                cntv++;
            }
        }
        
        int right=0;
        ans=cntv;
        for(int left = k;left<n;left++){
            if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] =='o' || s[left]=='u'){
                cntv++;
            }
            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] =='o' || s[right]=='u'){
                cntv--;
            }
            ans = max(ans,cntv);
            right++;
        }

        return ans;
    }
};