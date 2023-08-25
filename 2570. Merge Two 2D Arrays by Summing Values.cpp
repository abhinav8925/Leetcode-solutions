// Problem Link -> https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {

        
        
        

        unordered_map<int ,int> mp;
        for(auto &i: a)mp[i[0]] += i[1];
        for(auto &i: b)mp[i[0]] += i[1];

        vector<vector<int>> ans;

        for(auto &it:mp){
            ans.push_back({it.first,it.second});
        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};
