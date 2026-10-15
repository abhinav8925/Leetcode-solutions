class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        
        if(j == t.size())
            return 1;
        
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int a = 0;
        if(s[i] == t[j]){
            a = f(i+1,j,s,t,dp) +  f(i+1,j+1,s,t,dp);
        }
        else
            a = f(i+1,j,s,t,dp);
    
        return dp[i][j] = a;
    }
    
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        string lcs = t;
        
        vector<vector<int>> dp(n1,vector<int> (n2,-1));

        int ans = f(0,0,s,t,dp);
        
        return ans;
    }
};