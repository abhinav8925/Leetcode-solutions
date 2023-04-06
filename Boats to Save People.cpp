class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        int cost=0;
        int sum=0;
        int n=a.size();
        sort(a.begin(),a.end());
    
        for(int i=0,j=n-1;i<=j;)
        {
            if(a[i]+a[j]<=limit)
                {
                    cost++;
                    i++;
                    j--;
                }
            else
                {
                    cost++;
                    j--;
                }
        }
        return cost;
    }
};
