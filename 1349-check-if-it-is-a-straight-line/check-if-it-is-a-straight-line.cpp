// Problem Link -> https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution
{
    public:
        bool checkStraightLine(vector<vector < int>> &a) {

            int n = a.size();
            int x1 = a[0][0];
            int y1 = a[0][1];

            int x2 = a[1][0];
            int y2 = a[1][1];

            
            for(int i=2;i<n;i++){

                int  x = a[i][0];
                int  y = a[i][1];

                if( (x-x2) * (y-y1)  !=  (x-x1)*(y-y2))
                    return false;
                
            }


            return true;


        }
};