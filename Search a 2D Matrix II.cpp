// Problem Link -> https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {

        int row=a.size();
        int col=a[0].size();

        int sr=0,sc=col-1;

        while(sr<row && sc>=0){

            if(a[sr][sc]==x)
                return 1;
            else if(a[sr][sc]>x)
                sc--;
            else
                sr++;
        }

        return 0;
    }
};
