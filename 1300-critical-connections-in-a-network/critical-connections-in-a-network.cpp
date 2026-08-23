class Solution {
public:
    void dfs(vector<bool> &vis, int node, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low,int &cnt, int &parent,vector<vector<int>> &ans){

        vis[node] = true;
        tin[node] = cnt;
        low[node] = tin[node];
        cnt++;
        for(int i=0;i<adj[node].size();i++){
            int next = adj[node][i];
            if(next == parent)
                continue;
            if(!vis[next]){
                dfs(vis,next,adj,tin,low,cnt,node,ans);
                low[node] = min(low[node], low[next]);
                if(low[next] > tin[node]){
                    ans.push_back({node,next});
                }      
            }
            else
                low[node] = min(low[node],tin[next]);
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {

        vector<vector<int>> adj(n);
        vector<int> tin(n),low(n);
        vector<bool> vis(n,false);

        for(int i=0;i<con.size();i++){
            int a = con[i][0];
            int b = con[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);

        }
        vector<vector<int>> ans;
        int cnt = 0,par=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,i,adj,tin,low,cnt ,par, ans);
            }
        }
        
        return ans;


        
    }
};