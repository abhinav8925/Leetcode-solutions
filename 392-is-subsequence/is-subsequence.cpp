class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(),n2 = t.size();

        int j=0;
        for(int i=0;i<n2;i++){
            if(t[i] == s[j])
                j++;
        }
        if(j == n1) return true;
        return false;
    }
};