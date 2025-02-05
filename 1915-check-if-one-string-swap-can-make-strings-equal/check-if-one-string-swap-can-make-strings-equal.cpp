class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>pos;
        int cont = 0; 
        int sz = s1.size();
        for( int i = 0; i < sz; i++){
            if(s1[i] != s2[i]){
                cont++;
                pos.push_back(i);
            }
        }
        if(cont == 0 )
            return true;
        else if( cont == 2 && s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]])
            return true;
        return false;
    }
};