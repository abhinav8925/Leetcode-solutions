class Solution {
public:
    int pivotInteger(int n) {
        int rt = (n*(n+1))/2,lt=0;

        for(int i=n;i>=1;i--){
            lt+=i;
            if(lt==rt)
                return i;
            
            
            rt-=i;
        }
        return -1;
    }
};