// Problem Link -> https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(int cur,vector<int> &path, vector<vector<int>>& ans, vector<vector<int>> &graph){

        path.push_back(cur);
        if(cur==graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto x : graph[cur]){
                dfs(x,path,ans,graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path;
        vector<vector<int>> ans;

        dfs(0,path,ans,graph);

        return ans;
        
    }
};