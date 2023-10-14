// Problem Link -> https://leetcode.com/problems/painting-the-walls/?envType=daily-question&envId=2023-10-14


class Solution {
public:

    int f(vector<int> &cost,vector<int> &time, vector<vector<int>> &dp,int i,int k){

            if(k<=0)
                return 0;
            
            if(i<0)
                return 1000000000;
            
            if(dp[i][k] != -1)
                return dp[i][k];
            
            int take = cost[i] + f(cost,time,dp,i-1,k-time[i]-1);
            int ntake  = f(cost,time,dp,i-1,k);
        

            return dp[i][k] = min(take,ntake);




    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        vector<vector<int>> dp(time.size() +1 ,vector<int> (cost.size()+1 ,-1));

        return f(cost,time,dp,time.size()-1,cost.size());
    }
};