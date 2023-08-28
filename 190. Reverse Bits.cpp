// Problem Link -> https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0,temp=n,bit;

        for(int i=0;i<=31;i++){
            bit=(temp >> i)&1;

            res=res|(bit<<(31-i));
        }

        return res;
    }
};
