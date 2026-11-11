class Solution {
public:
    vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    using P = pair<int,pair<int,int>>;
    
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> res(n,vector<int>(n,INT_MAX));

        priority_queue<P,vector<P>, greater<P>> pq;

        res[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            int cur_time = pq.top().first;
            int node_r = pq.top().second.first;
            int node_c = pq.top().second.second;

            pq.pop();

            if(node_r == n-1 && node_c == n-1)
                return cur_time;
            
            if(cur_time > res[node_r][node_c])
                continue;
            
            for(auto it:dir){
                int i = node_r+it[0];
                int j = node_c+it[1];

                if(i>=0 && i<n && j>=0 && j<n){
                    int new_time = max(cur_time,grid[i][j]);
                    if(new_time < res[i][j]){
                        res[i][j] = new_time;
                        pq.push({new_time,{i,j}});
                    }
                }
            }
        }   

        return -1; 
    }
};