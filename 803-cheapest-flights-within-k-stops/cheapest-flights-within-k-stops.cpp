class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& mat, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<mat.size();i++){
            int u = mat[i][0];
            int v = mat[i][1];
            int cost = mat[i][2];

            adj[u].push_back({v,cost});
        }

        priority_queue<pair<pair<int,int>,int>,
                        vector<pair<pair<int,int>,int>>,
                        greater<pair<pair<int,int>,int>>> pq;
        
        
        int stops = k+1;
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));

        dist[src][0] = 0;
        pq.push({{0,src},0});

        while(!pq.empty()){
            int node = pq.top().first.second;
            int cost = pq.top().first.first;
            int cur_stops = pq.top().second;

            pq.pop();
            if(node == dst)
                return cost;
            if(cur_stops >= stops)
                continue;
            
            
            for(int i=0;i<adj[node].size();i++){
                int nbr = adj[node][i].first;
                int wt = adj[node][i].second;

                int new_cost = cost + wt;

                if(dist[nbr][cur_stops + 1] > new_cost) {
                    dist[nbr][cur_stops + 1] = new_cost;
                    pq.push({{new_cost, nbr}, cur_stops + 1});
                }
                
            
            }
        }

        return -1;

    }
};