// Problem Link -> https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:

    int dfs(vector<vector<int>> grid,int x,int y,int zero){

        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1){
            return 0;
        }
        if(grid[x][y]==2)
            return zero == -1?1:0;

        grid[x][y] = -1;
        zero--;
        int tp = dfs(grid,x+1,y,zero)+dfs(grid,x-1,y,zero)+dfs(grid,x,y+1,zero)+dfs(grid,x,y-1,zero);

        grid[x][y]=0;
        zero++;
        return tp;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int zero = 0;
        int sx=0,sy=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0)
                    zero++;
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;

                }
            }
        }
        return dfs(grid,sx,sy,zero);
        
    }
};