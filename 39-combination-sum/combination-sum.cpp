// Problem Link -> https://leetcode.com/problems/combination-sum/

class Solution
{
    public:

        void comb(int ind, int n, int target, vector<int> &ds, vector<int> &a, vector< vector< int>> &ans)
        {
            if (ind == n)
            {
                if (target == 0)
                {
                    ans.push_back(ds);
                }
                return;
            }

            if (a[ind] <= target)
            {
                ds.push_back(a[ind]);
                comb(ind, n, target - a[ind], ds, a, ans);
                ds.pop_back();
            }
            comb(ind + 1, n, target, ds, a, ans);
        }

    vector<vector < int>> combinationSum(vector<int> &a, int target)
    {
        int n = a.size();
        vector<vector < int>> ans;
        vector<int> ds;

        comb(0, n, target, ds, a, ans);
        return ans;
    }
};