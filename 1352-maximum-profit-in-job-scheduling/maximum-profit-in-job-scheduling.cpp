class Solution {
public:

    int solve(int idx, vector<vector<int>> &vec, vector<int> &dp, vector<int> &startTime)
    {
        if(idx == vec.size())
        {
            return 0;
        }

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        int ntake = solve(idx+1,vec,dp,startTime);
        
        int next = lower_bound(startTime.begin(),startTime.end(), vec[idx][1]) - startTime.begin();

        int take = vec[idx][2] + solve(next, vec, dp, startTime);

        return dp[idx] = max(take,ntake); 

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        {
            startTime[i] = vec[i][0];
        }

        vector<int> dp(n+1,-1);

        return solve(0,vec,dp,startTime);

    }
};