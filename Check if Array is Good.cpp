// Problem Link -> https://leetcode.com/contest/biweekly-contest-109/problems/check-if-array-is-good/

class Solution {
public:
    bool isGood(vector<int>& a) {
        int n=a.size();
        
        sort(a.begin(),a.end());

        
        for(int i=0;i<n-1;i++){
            if(a[i]!=i+1)
                return false;
        }
        if(a[n-1]!=(n-1))
            return false;
        return true;
    }
};
