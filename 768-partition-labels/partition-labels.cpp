class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char,pair<int,int>> mp;

        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first = min(i,INT_MAX);
                mp[s[i]].second = max(i,INT_MIN);
            }else{
                mp[s[i]].second = max(i,INT_MIN);
            }
            
        }

        // for(auto s:mp){
        //     cout <<s.first << " -> " << s.second.first << " " << s.second.second<< endl;
        // }
        
        vector<int> ans;

        for(int i=0;i<n;){
            int ss=mp[s[i]].first;
            int e=mp[s[i]].second;

            for(int j=ss;j<=e;j++){
                e = max(e,mp[s[j]].second);
            }
            ans.push_back(e-ss+1);
            i=e+1;
        }
        return ans;
    }
};