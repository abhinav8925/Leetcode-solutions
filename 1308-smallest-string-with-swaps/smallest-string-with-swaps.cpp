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

    int findParent(int a){
        if(parent[a] == a)  return a;
        return parent[a] = findParent(parent[a]);
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        DSU DSU1(n);

        for(int i=0;i<pairs.size();i++){
            int a = pairs[i][0];
            int b = pairs[i][1];

            DSU1.uni(a,b);
        }

        map<int,vector<char>> bucket;

        for(auto &it:DSU1.parent){
            int par = DSU1.findParent(it.first);
            bucket[par].push_back(s[it.first]);
        }

        map<int,queue<char>> ansMaker;
        for(auto &it:bucket){
            string s2 = "";
            
            for(int i=0;i<it.second.size();i++){
                s2+=it.second[i];
            }
            sort(s2.begin(),s2.end());
            for(int i=0;i<s2.size();i++){
                ansMaker[it.first].push(s2[i]);
            }
        }

        for(auto &it: DSU1.parent){
            
            char cur = ansMaker[it.second].front();
            ansMaker[it.second].pop();
            s[it.first] = cur;
        }
        
        
        return s;
    }
};