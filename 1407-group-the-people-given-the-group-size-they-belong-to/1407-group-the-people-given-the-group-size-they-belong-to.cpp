// Problem Link -> https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            int sz = a[i];
            mp[sz].push_back(i);
            if(mp[sz].size() == sz){
                ans.push_back(mp[sz]);
                mp[sz].clear();
            }
        }
        

        return ans;
    }
};