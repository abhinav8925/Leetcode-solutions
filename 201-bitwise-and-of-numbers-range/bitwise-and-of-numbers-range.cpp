//  This is because Brian Kernighan's Algorithm clears the rightmost set bit in each iteration, which typically requires fewer iterations compared to iterating through the entire range. In fact the time complexity is dependent on number of bits. An integer n has log(n) bits, hence the worst case is O(log(n)).
class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        
       
       while(l<r){
           r = r&(r-1);
       }
       return r;
    }
};