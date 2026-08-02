class DSU{
    public: 
        map<pair<int,int>, pair<int,int>> parent;
        map<pair<int,int>,int> size;
        

        DSU(int n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    parent[{i,j}] = {i,j};
                    size[{i,j}] = 1;
                }
            }
        }

        pair<int,int> findParent(pair<int,int> i){
            if(parent[i] == i)  return i;

            return parent[i] = findParent(parent[i]);
        }

        void uni(pair<int,int> p, pair<int,int> q){

            pair<int,int> a = findParent(p);
            pair<int,int> b = findParent(q);

            if(a==b)    return;

            if(size[a] >= size[b]){
                parent[b] = a;
                size[a] += size[b];
            }else{
                parent[a] = b;
                size[b] += size[a];
            }

        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DSU DSU1(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // top
                if(i>0){
                    if(grid[i][j] == 1 && grid[i-1][j] ==1){
                        DSU1.uni({i,j},{i-1,j});
                    }
                }

                // bottom
                if(i<n-1){
                    if(grid[i][j] == 1 && grid[i+1][j] ==1){
                        DSU1.uni({i,j},{i+1,j});
                    }
                }

                //right
                if(j<n-1){
                    if(grid[i][j] == 1 && grid[i][j+1] ==1){
                        DSU1.uni({i,j},{i,j+1});
                    }
                }

                //left
                if(j>0){
                    if(grid[i][j] == 1 && grid[i][j-1] ==1){
                        DSU1.uni({i,j},{i,j-1});
                    }
                }
            }
        }

        bool flg=false;

        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pair<int,int> p1,p2,p3,p4;
                if(grid[i][j]==0){
                    flg=true;
                    set<pair<int,int>> neighbour;
                    int temp=0;
                    //top neighbour
                    if(i>0){
                        if(grid[i-1][j] == 1){
                            p1 = DSU1.findParent({i-1,j});
                            neighbour.insert(p1);
                        }
                    }

                    //bottom neighbour
                    if(i<n-1){
                        if(grid[i+1][j] == 1){
                            p2 = DSU1.findParent({i+1,j});
                            neighbour.insert(p2);
                        }
                    }

                    //right neighbour 
                    if(j<n-1){
                        if(grid[i][j+1] == 1){
                             p3 = DSU1.findParent({i,j+1});
                            neighbour.insert(p3);
                        }
                    }

                    //left neighbour 
                    if(j>0){
                        if(grid[i][j-1] == 1){
                            p4 = DSU1.findParent({i,j-1});
                            neighbour.insert(p4);
                        }
                    }
                    for(auto &s:neighbour){
                        temp+=DSU1.size[s];
                    }
                    ans = max(temp+1,ans);
                    neighbour.clear();
                }


            }
        }

        if(flg) return ans;
        return n*n;
        

        
    }
};