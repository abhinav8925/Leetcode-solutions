class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        map<vector<int>, vector<string>> mp;

        for(int i=0;i<str.size();i++){
            string s1 = str[i];

            vector<int> freq(26,0);

            for(int i=0;i<s1.size();i++){
                freq[s1[i]-'a']++;
            }

            mp[freq].push_back(s1);
        }

        vector<vector<string>> ans;

        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};