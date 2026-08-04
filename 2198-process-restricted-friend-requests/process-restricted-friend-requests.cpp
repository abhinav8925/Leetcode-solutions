class DSU{
    public: 

    map<int,int> parent;
    map<int,int> size;

    DSU(int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int i){
        if(parent[i] == i)  return i;

        return parent[i] = findParent(parent[i]);
    }

    void uni(int p, int q){
        int a = findParent(p);
        int b = findParent(q);

        if(a == b)  return;

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
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        

        DSU DSU1(n);
        vector<bool> ans;

        for(int i=0;i<req.size();i++){
            int a = req[i][0];
            int b = req[i][1];
            if (DSU1.findParent(a) == DSU1.findParent(b)) {
                ans.push_back(true);
                continue;
            }
            bool ch = true;
            for(int i=0;i<res.size();i++){
                int c = res[i][0];
                int d = res[i][1];

                if((DSU1.findParent(c) == DSU1.findParent(a) && DSU1.findParent(d) == DSU1.findParent(b)) || (DSU1.findParent(c) == DSU1.findParent(b) && DSU1.findParent(d) == DSU1.findParent(a))){
                    ans.push_back(false);
                    ch=false;
                    break;
                }
            }
            if(ch){
                DSU1.uni(a,b);
                ans.push_back(true);
            }
        }
        return ans;
    }
};