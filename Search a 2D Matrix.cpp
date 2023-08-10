// Problem Link -> https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;

	/*

		int row=matrix.size();
        int col=matrix[0].size();

        int s=0,e=(row*col)-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            int check=matrix[mid/col][mid%col];

            if(check==target){
                return 1;
            }
            else if(check>target)
                e=mid-1;
            else
                s=mid+1;
        }


        return 0;

	*/
     }
};
