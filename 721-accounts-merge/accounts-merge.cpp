#include <bits/stdc++.h>
class DSU{
    public: 
        map<string, string> parent;
        map<string, int> size;
    
        void setParent(string s){
            parent[s] = s;
            size[s] = 1;
        }

        string findParent(string s){
            if(parent[s] == s)  return s;

            return parent[s] = findParent(parent[s]);
        }

        void union1(string p){
            parent[p] = p; 
        }
        void union2(string p, string q){
            string a = findParent(p);
            string b = findParent(q);

            if(a==b)
                return ;

            if(size[a] >= size[b]){
                parent[b] = a;
                size[a] += size[b];
            }else{
                parent[a] = b;
                size[b] += size[a];
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& pre) {

        map<string, string> mp;
        
        DSU DSU1;
        for(int i=0;i<pre.size();i++){
            for(int j=1;j<pre[i].size();j++){
                DSU1.setParent(pre[i][j]);
            }
        }

        for(int i=0;i<pre.size();i++){
            for(int j=1;j<pre[i].size();j++){
                mp[pre[i][j]] = pre[i][0];
            }
        }



        for(int i=0;i<pre.size();i++){
            if(pre[i].size() == 2){
                DSU1.union1(pre[i][1]);
                continue;
            }else{
                for(int j=1;j<pre[i].size()-1;j++){
                    DSU1.union2(pre[i][j], pre[i][j+1]);
                }
            }
        }

        map<string, vector<string>> bucket;

        for(auto &it: DSU1.parent){
            string root = DSU1.findParent(it.first);
            bucket[root].push_back(it.first);
            
        }

        vector<vector<string>> ans;

        for(auto &it: bucket){
            sort(it.second.begin(), it.second.end());
            string s = it.first;
            string s2 = mp[s];
            vector<string> temp;
            temp.push_back(s2);
            for(int i=0;i<it.second.size();i++){
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};