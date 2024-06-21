class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& g, int m) {
        int n = cus.size();
        int crun = 0;
        for(int i=0;i<m;i++){
            crun+=cus[i]*g[i];
        }

        int i=0,j=m;
        int mxun=crun;
        while(j<n){
            crun+=cus[j]*g[j];
            crun-=cus[i]*g[i];

            mxun = max(mxun,crun);
            i++;
            j++;
        }

        int tot = mxun;
        for(int i=0;i<n;i++)
            tot+=cus[i]*(1-g[i]);
        
        return tot;
    }
};