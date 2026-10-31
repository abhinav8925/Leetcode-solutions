class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({{0,0},1});
        vis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int wt = it.second;

            q.pop();
            if(row == n-1 && col == m-1)
                return wt;
            for(int r = -1;r<=1;r++){
                for(int c = -1;c<=1;c++){
                    int new_r = row+r;
                    int new_c = col+c;

                    if(new_r >=0 && new_r <=n-1 && new_c>=0 && new_c<=m-1
                        && vis[new_r][new_c]==0 && grid[new_r][new_c] ==0){
                            vis[new_r][new_c]=1;
                            q.push({{new_r,new_c},wt+1});
                        }
                }
            }
        }

        return -1;
    }
};