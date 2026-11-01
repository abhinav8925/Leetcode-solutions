class Solution {
public:
    int networkDelayTime(vector<vector<int>>& mat, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<mat.size();i++){
            int u = mat[i][0];
            int v = mat[i][1];
            int wt = mat[i][2];

            adj[u].push_back({v,wt});
        }

        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            if(dist[node] < wt)
                continue;
            for(int i=0;i<adj[node].size();i++){
                int nbr = adj[node][i].first;
                int cost = adj[node][i].second;
                int new_cost = wt + cost;

                if(dist[nbr] > new_cost){
                    dist[nbr] = new_cost;
                    pq.push({new_cost,nbr});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,dist[i]);
            if(dist[i] == 1e9)
                return -1;
        }
        return ans;
    }
};