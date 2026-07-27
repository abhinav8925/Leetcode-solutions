class DSU{
    public: 

    vector<int> parent,size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)    
            parent[i] = i;

    }

    int findParent(int i){
        if(parent[i] == i)  
            return i;

        return parent[i] = findParent(parent[i]);
    }

    bool unionBySize(int p, int q){
        int a = findParent(p);
        int b = findParent(q);

        if(a == b)  return false;

        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }else{
            parent[a] = b;
            size[b] += size[a];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& pre) {
        

        int n = pre.size();
        DSU DSU1(n+1);

        vector<int> ans;
        for(int i=0;i<pre.size();i++){
            int a = pre[i][0];
            int b = pre[i][1];

            if(!(DSU1.unionBySize(a,b))){
                ans = {a,b};
            }
        }
        return ans;
    }
};