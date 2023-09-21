// Problem Link -> https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {

       long long ones = n^(n>>1);

       return !(ones &(ones+1));

        
    }
};