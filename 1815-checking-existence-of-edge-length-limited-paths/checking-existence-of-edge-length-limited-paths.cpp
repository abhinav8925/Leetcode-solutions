class DSU{
    public: 
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            size.resize(n,1);

            for(int i=0;i<n;i++)    parent[i] = i;
        }

        int findParent(int n){
            if(parent[n] == n)  return n;
            return parent[n] = findParent(parent[n]);
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& que) {

        DSU DSU1(n);

        vector<vector<int>> sorted;
        vector<bool> ans(que.size());

        for(int i=0;i<que.size();i++){
            sorted.push_back({
                que[i][0],
                que[i][1],
                que[i][2],
                i
            });
        }

        sort(sorted.begin(), sorted.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        sort(edge.begin(),edge.end(),[](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });

        int j=0;
        for(int i=0;i<sorted.size();i++){
            int limit = sorted[i][2];
            while(j<edge.size() && edge[j][2] < limit){
                DSU1.uni(edge[j][0],edge[j][1]);
                j++;
            }
            if(DSU1.findParent(sorted[i][0]) == DSU1.findParent(sorted[i][1]))
                ans[sorted[i][3]] = true;
            else
                ans[sorted[i][3]] = false;
        }

        return ans;
        
    }
};