// Problem Link -> https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:

    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int row=mat.size(),col=mat[0].size();

        

        for(int i=0;i<row;i++){

                int low=0,high=col-1;

                while(low<=high){
                        
                        int mid=(low+high)/2;

                        int up= i>0 ? mat[i][mid] : -1;
                        int lo= i<row-1 ? mat[i+1][mid] : -1;
                        int le= mid>0 ? mat[i][mid-1] : -1;
                        int rt= mid<col-1 ? mat[i][mid+1] : -1;

                        int mxvertical= max(up,lo);
                        int mxhorizontal = max(le,rt);

                        int lhf=max(mat[i][0] ,le);
                        int rhf=max(rt,mat[i][col-1]);
                        int maxoverall = max(mxvertical,mxhorizontal);

                        if(mat[i][mid] >= maxoverall ){

                            return {i,mid};
                        }
                        else if(lhf>rhf)
                            high=mid-1;
                        else
                            low=mid+1;
                    
                }
        }

        return {-1,-1};

        
    }
};
