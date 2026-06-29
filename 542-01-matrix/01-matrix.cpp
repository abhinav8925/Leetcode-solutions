class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n,0));

        queue<pair<int,int>> q;

        bool ch = true;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    ch = false;
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();
                
                if(row+1 <m){
                    if(mat[row+1][col] == 1){
                        ans[row+1][col] = ans[row][col]+1;
                        q.push({row+1,col});
                        mat[row+1][col] = 0;
                    }
                }
                if(row-1>=0){
                    if(mat[row-1][col] == 1){
                        ans[row-1][col] = ans[row][col]+1;
                        q.push({row-1,col});
                        mat[row-1][col] = 0;
                    }
                }
                if(col+1 <n){
                    if(mat[row][col+1] == 1){
                        ans[row][col+1] = ans[row][col]+1;
                        q.push({row,col+1});
                        mat[row][col+1] = 0;
                    }
                }
                if(col-1 >=0){
                    if(mat[row][col-1] == 1){
                        ans[row][col-1] = ans[row][col]+1;
                        q.push({row,col-1});
                        mat[row][col-1] = 0;
                    }
                }

            }

        }

        if(!ch) return ans;
        return mat;
    }
};