// Problem Link -> https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));

        int cnt=1;
        int sr=0,sc=0,er=n-1,ec=n-1;
        while(cnt<=(n*n)){

            for(int i=sc;i<=ec && cnt<=(n*n);i++){
                v[sr][i]=cnt;
                cnt++;
            }
            sr++;

            for(int i=sr;i<=er && cnt<=(n*n);i++){
                v[i][ec]=cnt;
                cnt++;
            }
            ec--;

            for(int i=ec;i>=sc && cnt<=(n*n);i--){
                v[er][i]=cnt;
                cnt++;
            }
            er--;

            for(int i=er;i>=sr && cnt<=(n*n);i--){
                v[i][sc]=cnt;
                cnt++;
            }
            sc++;
            
        }

        return v;

    }
};
