class Solution {
public:
    void f(int &n, int left, int right, string temp, vector<string> &ans){

        if(left == n && right == n){
            ans.push_back(temp);
            return;
        }

        if(left < n){
            f(n,left+1,right,temp+'(',ans);
            
        }
        if(right < left){
            f(n,left,right+1,temp+')',ans);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
    

        f(n,0,0,temp,ans);
        return ans;
    }
};