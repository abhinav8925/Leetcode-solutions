class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int cnt = 0;
        while(!q.empty()){
            bool ch = false;
            int sz = q.size(); 
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r+1 <n){
                    if(grid[r+1][c] == 1){
                        grid[r+1][c] = 2;
                        q.push({r+1,c});
                        ch=true;
                        }
                    }
                if(c+1 <m){
                    if(grid[r][c+1] == 1){
                        grid[r][c+1]=2;
                        q.push({r,c+1});
                        ch=true;
                        }
                    }
                if(r-1 >=0){
                    if(grid[r-1][c] == 1){
                        grid[r-1][c]=2;
                        q.push({r-1,c});
                        ch=true;
                        }
                    }
                if(c-1 >=0){
                    if(grid[r][c-1] == 1){
                        grid[r][c-1]=2;
                        q.push({r,c-1});
                        ch=true;
                    }
                }
            }
            if(ch)
                cnt++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return cnt;
    }
};