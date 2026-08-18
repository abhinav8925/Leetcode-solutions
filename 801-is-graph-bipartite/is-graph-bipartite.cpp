class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &color, int &i){

        for(int j=0;j<adj[i].size();j++){
            int next = adj[i][j];
            if(color[next] == 2){
                color[next] = !(color[i]);
                if(!dfs(adj,color,next))
                    return false;
            }else{
                if(color[i] == color[next])
                    return false;
            }
        }
        return true;
        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> adj (n,vector<int> ());
        vector<int> color(n,2);

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == 2){
                color[i] = 1;
                if(!dfs(adj,color,i))
                    return false;
            }
        }

        return true;
    }
};