// Problem Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int profit=0,mn=a[0],n=a.size();


        for(int i=1;i<n;i++){
            int cost=a[i]-mn;
            
            profit=max(profit,cost);
            mn=min(mn,a[i]);
        }

        return profit;
    }
};
