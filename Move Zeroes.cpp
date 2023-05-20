// Problem Link -> https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        for(int i=0,j=0;j<n;)
        {
            if(a[j]==0)
                j++;
            else if(a[j]!=0)
            {
                swap(a[i],a[j]);
                i++;
                j++;
            }
        }
    }
};
