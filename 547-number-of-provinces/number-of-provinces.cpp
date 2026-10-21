class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;

        for(int i=0;i<adj[node].size();i++){
            int neighbor = adj[node][i];
            if(!vis[neighbor])
                dfs(neighbor,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& comp) {
        int n = comp.size();
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<comp[i].size();j++){
                if(comp[i][j] == 1){
                    int a = i,b=j;
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }

        return cnt;
    }
};