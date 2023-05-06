
// Problem Link -> https://leetcode.com/problems/richest-customer-wealth/description/



class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int mx=0;
        for(int i=0;i<a.size();i++)
        {
            int sum=0;
            for(int j=0;j<a[0].size();j++)
            {
                sum+=a[i][j];
            }
            mx=max(sum,mx);
        }
        return mx;
    }

};
