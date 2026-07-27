#include<bits/stdc++.h>
class DSU{
    public: 

        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            size.resize(n,1);

            for(int i=0;i<n;i++)
                parent[i] = i;
        }

        int findParent(int i){
            if(parent[i] == i)  return i;

            return parent[i] = findParent(parent[i]);
        }

        void unionBysize(int p,int q, int &red){
            int a = findParent(p);
            int b = findParent(q);

            if(a==b){
                red++;
                return;
            }


            if(size[a]>size[b]){
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
    int makeConnected(int n, vector<vector<int>>& pre) {
        
        DSU DSU1(n);
        int red = 0;

        int m = pre.size();
        for(int i=0;i<m;i++){
            DSU1.unionBysize(pre[i][0],pre[i][1],red);
        }

        int con = 0;
        for(int i=0;i<n;i++){
            if(DSU1.findParent(i) == i)
                con++;
        }

        if(red >= con-1)    return con-1;
        return -1;
    }
};