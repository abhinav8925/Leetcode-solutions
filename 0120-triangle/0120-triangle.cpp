// Problem Link -> https://leetcode.com/problems/triangle/

class Solution {
public:

    int f(int i, int j, int n, vector<vector<int>>&a, vector<vector<int>>&dp) {
		if(i == n - 1)
			return a[i][j];
        
		if(dp[i][j] != -1)
			return dp[i][j];
		int down = a[i][j] + f(i+1, j, n, a, dp);
		int  diag = a[i][j] + f(i+1, j+1, n, a, dp);
		return dp[i][j] = min(down, diag);
	}
    int minimumTotal(vector<vector<int>>& a) {
        

        int n = a.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return f(0, 0, n, a, dp);
    }
};