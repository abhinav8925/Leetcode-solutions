class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<vector<int>> comb(difficulty.size(),vector<int> (2,0));

        int n = difficulty.size();
        for(int i=0;i<n;i++){
            comb[i][0] = difficulty[i];
            comb[i][1] = profit[i];
        }

        sort(comb.begin(),comb.end());
        sort(begin(worker),end(worker));
        int ans=0;

        int j=0,mx=0;
        for(int work: worker){
            while(j<size(worker) && work>=comb[j][0]){
                mx = max(mx,comb[j][1]);
                j++;
            }
            ans+=mx;
        }

        return ans;
    }
};