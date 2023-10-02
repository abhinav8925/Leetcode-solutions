
// Problem Link -> https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void rec(vector<string> &ans, int &ind,int open,int close,string ds){

        if(open == ind && close == ind){
            ans.push_back(ds);
            return;
        }
        if(open<ind)
            rec(ans,ind,open+1,close,ds+'(');
        
        if(close<open)
            rec(ans,ind,open,close+1,ds+')');
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string ds = "";
        rec(ans,n,0,0,ds);
        return ans;
    }
};