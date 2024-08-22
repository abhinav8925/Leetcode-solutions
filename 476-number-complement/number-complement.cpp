// Problem Link -> https://leetcode.com/problems/number-complement/

class Solution {
public:
int countbits(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n=n>>1;
    }
    return count;
}
    int findComplement(int num) {
        for(int i=0;i<countbits(num);i++)
        {
            num=num^(1<<i);
        }
        return num;
    }
};