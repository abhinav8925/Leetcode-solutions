
class DSU {
    vector<int> size, par;

public:
    DSU(int n) {
        par.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int n) {
        if(par[n] == n)
            return n;

        return par[n] = findpar(par[n]);
    }

    void uni(int u, int v) {
        int a = findpar(u);
        int b = findpar(v);

        if(a == b) return;

        if(size[a] >= size[b]) {
            par[b] = a;
            size[a] += size[b];
        } else {
            par[a] = b;
            size[b] += size[a];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mxr = 0, mxc = 0;

        for(auto it : stones) {
            mxr = max(mxr, it[0]);
            mxc = max(mxc, it[1]);
        }

        DSU ds(mxr + mxc + 1);

        unordered_map<int,int> unq;

        for(auto it : stones) {
            int nr = it[0];
            int nc = it[1] + mxr + 1;

            ds.uni(nr, nc);

            unq[nr] = 1;
            unq[nc] = 1;
        }

        int cnt = 0;

        for(auto it : unq) {
            if(ds.findpar(it.first) == it.first)
                cnt++;
        }

        return stones.size() - cnt;
    }
};
