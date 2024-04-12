class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0;
        int ans=0;
        for(int i=0;i<size(bank);i++){
            string che = bank[i];
            int cnt=0;
            int n = che.size();
            for(int i=0;i<n;i++){
                if(che[i]=='1')
                    cnt++;
            }
            if(cnt==0){
                continue;
            }
            else{
                
                ans+=(prev*cnt);
                prev = cnt;
            }

        }
        return ans;
    }
};