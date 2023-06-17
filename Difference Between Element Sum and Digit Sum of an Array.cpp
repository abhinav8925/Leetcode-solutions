// Problem Link -> https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution {
public:
    int differenceOfSum(vector<int>& a) {
        int cntd=0,cnte=0,n=a.size();

        for(int i=0;i<n;i++){
            cnte+=a[i];
            while(a[i]!=0){
                cntd+=(a[i]%10);
                a[i]/=10;
            }
        }

        return abs(cntd-cnte);
    }
};
