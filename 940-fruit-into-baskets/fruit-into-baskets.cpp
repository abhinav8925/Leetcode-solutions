class Solution {
public:
    int totalFruit(vector<int>& v) {

        int n =  v.size();
        int i=0,j=0,ans=0;
        map<int,int> mp;

        while(j<n){
            while(i<n && mp.size()>2){
                mp[v[i]]--;
                if(mp[v[i]] == 0){
                        mp.erase(v[i]);
                }
                i++;        
            }
            
            
            mp[v[j]]++;
            if(mp.size()<=2)
                ans = max(ans, j-i+1);
            j++;
        }

       
        return ans;
    }
};