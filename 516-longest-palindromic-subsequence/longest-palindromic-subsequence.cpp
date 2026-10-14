class Solution {
public:
    int f(int i, int j, string &s,vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(i == j)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int a = 0,b=0;
        if(s[i] == s[j])
            a = 2 + f(i+1,j-1,s,dp);
        else{
            a = f(i+1,j,s,dp);
            b = f(i,j-1,s,dp);
        }
        return dp[i][j] = max(a,b);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp);
    }
};