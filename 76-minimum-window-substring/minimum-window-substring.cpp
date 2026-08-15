class Solution {
public:
    string minWindow(string s, string t) {
        
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mp;

        
        for (char c : t) {
            mp[c]++;
        }

        int required = t.size();

        int left = 0;
        int ans = INT_MAX;
        int st = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            if (mp[c] > 0) {
                required--;
            }
                mp[c]--;


            while (required == 0) {
                if (right - left + 1 < ans) {
                    ans = right - left + 1;
                    st = left;
                }

                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return ans == INT_MAX ? "" : s.substr(st, ans);
    }
};