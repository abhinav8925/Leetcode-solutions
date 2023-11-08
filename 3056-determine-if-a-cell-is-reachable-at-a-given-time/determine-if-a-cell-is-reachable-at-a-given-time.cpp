class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx==fx && sy==fy){
            if(t==1)
                return false;
            return 1;
        }
        int x = abs(sx-fx),y = abs(sy-fy);
        if(max(x,y)>t)
            return 0;
        
        return 1;
    }
};