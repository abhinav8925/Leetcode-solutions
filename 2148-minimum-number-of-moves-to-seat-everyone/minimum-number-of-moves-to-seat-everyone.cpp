// Problem Link -> https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int sum=0;
        for(int i=0;i<a.size();i++){
            sum+=abs(a[i]-b[i]);
        }
        
        return sum;
    }
};