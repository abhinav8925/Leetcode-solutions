class DSU{
public: 
    vector<int> par, size;

    DSU(int n){
        par.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int findpar(int u){
        if(par[u] == u)
            return u;
        return par[u] = findpar(par[u]);

    }

    void uni(int u, int v){
        int a = findpar(u);
        int b = findpar(v);

        if(a == b)
            return;
        
        if(size[a] > size[b]){
            par[b] = a;
            size[a] += size[b];
        }else{
            par[a] = b;
            size[b] += size[a];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& grid) {
        
        int sz = grid.size();
        if(sz < n-1)
            return -1;
        
        int cnt = 0;

        DSU ds(n);

        for(int i=0;i<grid.size();i++){
            int a = grid[i][0];
            int b = grid[i][1];

            if(ds.findpar(a) != ds.findpar(b)){
            
                ds.uni(a,b);
            }
        }

        for(int i=0;i<n;i++){
            if(ds.findpar(i) == i)
                cnt++;
        }
        
        return cnt-1;
    }
};