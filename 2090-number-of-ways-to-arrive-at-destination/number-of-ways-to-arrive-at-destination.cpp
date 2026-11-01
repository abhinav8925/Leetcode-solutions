
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& mat) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<mat.size();i++){
            int u = mat[i][0];
            int v = mat[i][1];
            int wt = mat[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        int mod = 1e9+7;

        pq.push({0,0});

        while(!pq.empty()){

            int node = pq.top().second;
            long long wt = pq.top().first;

            pq.pop();

            if(dist[node] < wt)
                continue;

            for(int i=0;i<adj[node].size();i++){

                int nbr = adj[node][i].first;
                int cost = adj[node][i].second;

                long long new_cost = wt + cost;

                if(dist[nbr] > new_cost){

                    dist[nbr] = new_cost;
                    ways[nbr] = ways[node];

                    pq.push({new_cost,nbr});

                }
                else if(dist[nbr] == new_cost){

                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
