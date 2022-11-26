// Date -> 26th November 2022
// Code by -> Abhinav Anand

// Problem Link -> https://leetcode.com/contest/biweekly-contest-92/problems/minimum-cuts-to-divide-a-circle/

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1)
                return 0;
        else if(n%2==0 && n>1)
                return n/2;
        else
                return n;
    }
};