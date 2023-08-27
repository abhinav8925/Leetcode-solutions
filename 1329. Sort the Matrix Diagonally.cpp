// Problem Link -> https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

    // first way we can solve this problem is by using an extra space as well as inbuilt sorting sunction
    // an efficient way is to solve by using the count sort method as constraints are not that big.

    // first go through evrey diagonal and store them into a set and then put it back oon the matrix from the starting of the diagonal -> go throough every diagonal and sort it



        int m=mat.size(),n=mat[0].size();
        //first row
        for(int i=0;i<n;i++){
            int row=0,col=i;
            vector<int>temp;
            while(row<m && col<n){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(),temp.end());
            row=0;
            col=i;
            int ind=0;
            while(row<m && col<n){
                mat[row][col]=temp[ind];
                row++;
                col++;
                ind++;    
            }
    }
        //first col
        for(int j=1;j<m;j++){
            int row=j,col=0;
            vector<int>temp;
            while(row<m && col<n){
                    temp.push_back(mat[row][col]);
                    row++;
                    col++;
                }
            sort(temp.begin(),temp.end());
            row=j;
            col=0;
            int ind=0;
            while(row<m && col<n){
                    mat[row][col]=temp[ind];
                    row++;
                    col++;
                    ind++;    
            }
        }
    return mat;

    }
};
