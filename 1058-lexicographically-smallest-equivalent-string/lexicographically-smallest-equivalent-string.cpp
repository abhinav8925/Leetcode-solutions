class DSU{
    public:
        map<char,char> parent;
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

            if(a >= b){
                parent[a] = b;
                size[b] += size[a];
            }else{
                parent[b] = a;
                size[a] += size[b];
            }
        }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string s) {
        
        int n = s1.size();
        DSU DSU1(26);

        for(int i=0;i<n;i++){
            char a = s1[i];
            char b = s2[i];

            DSU1.uni(a,b);
        }

        for(int i=0;i<s.size();i++){
            char a = DSU1.findParent(s[i]);
            s[i] = a;
        }
        
        return s;
    }
};