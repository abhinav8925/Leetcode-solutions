// Problem Link -> https://leetcode.com/contest/weekly-contest-360/problems/furthest-point-from-origin/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int cnt=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L')
                    cnt--;
            else if(moves[i]=='R')
                    cnt++;
            else{
                cnt--;
            }
        }
        int cnt2=0;
        
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L')
                    cnt2--;
            else if(moves[i]=='R')
                    cnt2++;
            else{
                cnt2++;
            }
        }
        
        return max(abs(cnt),abs(cnt2));
    }
};
