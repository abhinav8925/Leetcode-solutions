class Solution {
public:
    int n,m;
    int maxGold = 0;

    int f(int r,int c,vector<vector<int>> &grid){
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0)
            return 0;
        
                
        int cur = grid[r][c];
        grid[r][c] = 0;
         int up = f(r - 1, c, grid);
        int left = f(r, c - 1, grid);
        int down = f(r + 1, c, grid);
        int right = f(r, c + 1, grid);
        
            
        int take = cur + max({up,left,right,down});
        
        grid[r][c] = cur;
        return take;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        n = grid.size(),m=grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, f(i,j,grid));
                }
            }
        }

        return maxGold;
    }
};