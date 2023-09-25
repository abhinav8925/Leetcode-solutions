// Problem Link -> https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int topdown(string& text1,string& text2,int i,int j,vector<vector<int>>& dp){
        if(i==text1.length()||j==text2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if(text1[i]==text2[j])
            ans=1+topdown(text1,text2,i+1,j+1,dp);
        else
            ans=max(topdown(text1,text2,i,j+1,dp),topdown(text1,text2,i+1,j,dp));
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0,j=0;
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return topdown(text1,text2,i,j,dp);
    }
};