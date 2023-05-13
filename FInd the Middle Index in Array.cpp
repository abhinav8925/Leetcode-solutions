// Problem Link -> https://leetcode.com/problems/find-the-middle-index-in-array/

// Brute Force and Optimal
class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        
        int leftsum=0;
        int rightsum=sum;
        for(int i=0;i<a.size();i++)
        {
            rightsum-=(a[i]);
            if(leftsum==rightsum)
                return i;
            
            leftsum=a[i]+leftsum;
        }
        return -1;
    }
};
