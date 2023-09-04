// Problem Link -> https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/

class Solution {
public:
    int isWinner(vector<int>& v1, vector<int>& v2) {
        
        int x = v1[0], y = v2[0];
        int i = 0, n = v1.size();
        for(i = 1; i < n; i++){
            if(i==1){
                if(v1[i-1]==10)x += v1[i]*2;
                else x += v1[i];
                if(v2[i-1]==10)y += v2[i]*2;
                else y += v2[i];
            }else{
                if(v1[i-1]==10||v1[i-2]==10)x += v1[i]*2;
                else x += v1[i];
                if(v2[i-1]==10||v2[i-2]==10)y += v2[i]*2;
                else y += v2[i];
            }
        }
        if(x>y)return 1;
        if(y>x)return 2;
        return 0;
    }
};