class DSU{
    public:
        map<char ,char> parent;
        map<char,int> size;

        DSU(int n){
            for(int i=0;i<n;i++){
                parent['a'+i] = 'a'+i;
                size['a'+i] = 1;
            }
        }

        char findParent(char s){
            if(parent[s] == s)  return s;
            return parent[s] = findParent(parent[s]);
        }

        void uni(char p, char q){
            char a = findParent(p);
            char b = findParent(q);

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
    bool equationsPossible(vector<string>& pre) {
        
        DSU DSU1(26);
        
        int n = pre.size();

        for(int i=0;i<n;i++){
            
            string s = pre[i];
            char s1 = s[0];
            char s2 = s[1];
            char s3 = s[3];
            
            if(s2 == '='){
                DSU1.uni(s1,s3);
            }else
                continue;
        }

        for(int i=0;i<n;i++){
            string s = pre[i];
            char s1 = s[0];
            char s2 = s[1];
            char s3 = s[3];

            if(s2 == '!'){
                if(DSU1.findParent(s1) == DSU1.findParent(s3))
                    return false;
            }else
                continue;
        }

        return true;
    }
};