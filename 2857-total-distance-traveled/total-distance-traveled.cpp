// Problem Link -> https://leetcode.com/problems/total-distance-traveled/

class Solution {
public:
    int distanceTraveled(int mt, int at) {

        int cnt=0,used=0;
        while(mt>0){

            used++;

            if(used%5 == 0 && at>0){
                at--;
                mt++;
            }
            
            mt--;
            cnt+=10;

        }

        return cnt;

        
    }
};