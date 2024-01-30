class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
     bool isSafe(vector<vector<int>>& isWater, int r, int c, vector<vector<int>>& heights){
        if(r < 0 || c < 0 || r == isWater.size() || c == isWater[0].size() || isWater[r][c] == 1 || heights[r][c] > 0){
            return false;
        }
        return true;
    }
    void bfs(vector<vector<int>> &v, vector<vector<int>> &ans,queue<pair<int,int>> &q){

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                int h = ans[i][j];

                for(int b=0;b<4;b++){
                    int ni = i+dx[b];
                    int nj = j+dy[b];
                    if(isSafe(v,ni,nj,ans)){
                        ans[ni][nj] = h + 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {

        int m = v.size();
        int n =  v[0].size();

        vector<vector<int>> ans(m,vector<int> (n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1)
                    q.push({i,j});
            }
        } 

        bfs(v,ans,q);
        return ans;
    }
};