class DSU{
    public: 
        map<int,int> parent;
        vector<int> size;

        DSU(int n){
            size.resize(n,1);
            
            for(int i=0;i<n;i++){
                parent[i]=i;
            
            }
        }

        int findParent(int n){
            if(parent[n] == n)  return n;
            return parent[n] = findParent(parent[n]);
        }

        void un(int p, int q){
            int a = findParent(p);
            int b = findParent(q);

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
    int removeStones(vector<vector<int>>& pre) {

        int m = pre.size();
        int mr=INT_MIN,mc=INT_MIN;
        for(int i=0;i<m;i++){
            mr = max(mr,pre[i][0]);
            mc = max(mc,pre[i][1]);
        }

        DSU DSU1(mr+mc+2);

        for(int i=0;i<m;i++){
            int a = pre[i][0];
            int b = pre[i][1];
            DSU1.un(a,mr+b+1);
        }

        
        set<int> s;
        for(int i=0;i<m;i++){
            int a = pre[i][0];
            int b = pre[i][1];
            if(DSU1.findParent(a)==a)
            s.insert(a);
            if( DSU1.findParent(b+mr+1) == b+mr+1)   
            s.insert(b);
         
        }

        
        return m-s.size();
        
    }
};