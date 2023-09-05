// Problem Link ->  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        
        
    int ans = 0, cnt = 0;
    int n = s.size();
    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
            cnt++;
        if (i - j + 1 == k) {
            ans = max(ans, cnt);
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i')
                cnt--;
            j++;
        }
        i++;
    }

    
    // if (ans == 0)
    //     return -1;

    return ans;
}



    
};