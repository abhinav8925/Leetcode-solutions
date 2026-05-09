class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char,int> mp;

        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }

        
        
        vector<int> ans;

        for(int i=0;i<n;){
            int e=mp[s[i]];

            for(int j=i;j<=e;j++){
                e = max(e,mp[s[j]]);
            }
            ans.push_back(e-i+1);
            i=e+1;
        }
        return ans;
    }
};