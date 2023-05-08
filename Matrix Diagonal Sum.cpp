
// Problem Link -> https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int rows=mat.size();
        int x=rows-1,y=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<rows;j++)
            {
                if(i==j)
                {
                        sum+=mat[i][j];
                        sum+=mat[x--][y++];
                }                
            }
        }
        
        
        if(rows%2==0)
            return sum;
        else
            return sum-mat[rows/2][rows/2];

        
    }
};
