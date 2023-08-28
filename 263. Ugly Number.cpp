// Problem Link -> https://leetcode.com/problems/ugly-number

class Solution {
public:

   
    bool isUgly(int n) {
        if(n<1)
            return false;
        
        
            if(n%2==0){
                while(n%2==0)
                    n/=2;
            }
            if(n%3==0){
                while(n%3==0)
                    n/=3;
            }
            if(n%5==0){
                while(n%5==0)
                    n/=5;
            }
            
        

        if(n==1)
            return 1;
        return 0;

    }
};
