class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();

        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) 
                    q.push({i,j});
            }
        }

        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            bool ch = true;

            while(sz-- ){

                int row = q.front().first;
                int col = q.front().second;

                q.pop();
                if(row+1 < m){
                    if(grid[row+1][col] == 1) {
                            grid[row+1][col]=2;
                            q.push({row+1,col});
                            ch=false;
                    }
                }
                    if(row-1>=0){
                        if(grid[row-1][col] == 1) {
                                grid[row-1][col]=2;
                                q.push({row-1,col});
                                ch=false;
                        }
                    }
                
                if(col+1<n){
                    if(grid[row][col+1] == 1){
                        grid[row][col+1]=2;
                            q.push({row,col+1});
                            ch=false;
                    }
                }
                if(col-1>=0){
                     if(grid[row][col-1] == 1){
                            grid[row][col-1]=2;
                            q.push({row,col-1});
                            ch=false;
                    }
                }

        }
            if(!ch) ans++;
    }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
        
    }
};




