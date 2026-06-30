class Solution {
public:

    int f(vector<vector<char>>& grid,int i, int j, vector<vector<char>>& vis){
        queue<pair<int,int>> q;
        int ch=0;
        int m = grid.size();
        int n = grid[0].size();

        if(vis[i][j] == '0'){
            q.push({i,j});
            while(!q.empty()){
                vis[i][j] = '1';

                int sz = q.size();
                while(sz--){
                    int row = q.front().first;
                    int col = q.front().second;

                    q.pop();

                        if(grid[row][col] == '1'){

                            if(row+1 < m && grid[row+1][col] == '1' && vis[row+1][col] == '0'){
                                q.push({row+1,col});
                                vis[row+1][col]='1';
                            }
                            if(row-1 >=0 && grid[row-1][col] == '1' && vis[row-1][col] == '0'){
                                q.push({row-1,col});
                                vis[row-1][col]='1';
                            }
                            if(col+1 < n && grid[row][col+1] == '1' && vis[row][col+1] == '0'){
                                q.push({row,col+1});
                                vis[row][col+1]='1';
                            }
                            if(col-1 >=0 && grid[row][col-1] == '1' && vis[row][col-1] == '0'){
                                q.push({row,col-1});
                                vis[row][col-1]='1';
                            }
                            
                        }
                    }
            }
                        ch++;
        }

        return ch;

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<char>> vis(m,vector<char> (n,'0'));

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    
                    ans += f(grid, i,j,vis);
                }
            }
        }

        return ans;
    }

};


