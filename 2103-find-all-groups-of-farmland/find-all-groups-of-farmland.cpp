class Solution {
public:
    int m,n;
    vector<vector<int>> res;
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>> &land,int i,int j, int &r2, int &c2){

        land[i][j]=0;
        r2 =max(r2,i);
        c2 = max(c2,j);

        for(auto &dir :dirs){
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            if(i_>=0 && i_<m && j_>=0 && j_<n && land[i_][j_]==1){
                dfs(land,i_,j_,r2,c2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

     
        m = land.size();
        n = land[0].size();
     for(int i=0;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1){
                int r1 = i,r2=-1;
                int c1 = j,c2=-1;
                dfs(land,i,j,r2,c2);
                res.push_back({r1,c1,r2,c2});
            }
        }
     }   
     return res;
    }
};