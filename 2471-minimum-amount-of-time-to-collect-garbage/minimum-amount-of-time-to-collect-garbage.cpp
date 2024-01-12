class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {

        int ans=0;
        int n = g.size();
        int lm=-1, lg=-1, lp=-1;

        for(int i=n-1;i>=0;i--){
            if(lm==-1 && g[i].find("M")!=string::npos)
                lm=i;
            if(lp==-1 && g[i].find("P")!=string::npos)
                lp=i;
            if(lg==-1 && g[i].find("G")!=string::npos)
                lg=i;
            
            if(lp!=-1 && lg!=-1 && lm!=-1)
                break;
        }

        for(auto it:g){
            ans+=it.size();
        }
         if(lm!=-1)
                ans=accumulate(t.begin(),t.begin()+lm,ans);
         if(lp!=-1)
                ans=accumulate(t.begin(),t.begin()+lp,ans);
         if(lg!=-1)
                ans=accumulate(t.begin(),t.begin()+lg,ans);
        

        return ans;
    }
};