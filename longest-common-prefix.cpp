class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]!=strs[n-1][i])break;
            prefix+=strs[0][i];
        }
        return prefix;
    }
};
