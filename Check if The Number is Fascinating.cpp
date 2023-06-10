// Problem Link -> https://leetcode.com/contest/biweekly-contest-106/problems/check-if-the-number-is-fascinating/


class Solution {
public:
    bool isFascinating(int n) {
        int num1=2*n;
        int num2=3*n;
        
        vector<int> v(10,0);
        while(n!=0){
            int k=n%10;
            v[k]++;
            n=n/10;
        }
        while(num1!=0){
            int k=num1%10;
            v[k]++;
            num1=num1/10;
        }
        while(num2!=0){
            int k=num2%10;
            v[k]++;
            num2=num2/10;
        }
        
        bool ans=true;
        for(int i=1;i<10;i++){
            if(v[i]!=1){
                ans=false;
                break;
            }
        }
        
        if(ans)
                return true;
        else
                return false;
    }
};
