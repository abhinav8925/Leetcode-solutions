class Solution {
public: 
    bool dfs(vector<bool> &vis, int node, vector<vector<int>> &adj, vector<bool> &curr,vector<int> &ans){
        vis[node] = true;
        curr[node] = true;

        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];

            if(curr[next] == true)
                return false;
            
            if(!vis[next])  
                if(!dfs(vis, next,adj,curr,ans)) 
                    return false;
        }

        curr[node] = false;
        ans.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(numCourses,vector<int>());

        for(int i=0;i<pre.size();i++){
            int a = pre[i][0];
            int b = pre[i][1];        

            adj[b].push_back(a);
        }

        vector<bool> vis(numCourses,false),curr(numCourses,false);
        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(vis,i,adj,curr,ans))
                    return {};
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};