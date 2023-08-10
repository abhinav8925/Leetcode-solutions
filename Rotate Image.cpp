// Problem Link -> https://leetcode.com/problems/rotate-image/description/


// using extra space (brute force)

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
       /*
       // using extra space (brute force)
        int n = a.size();
    int m = a[0].size();
    vector<vector<int>> v(n, vector<int>(m));
    int x = 0, y = m - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[x][y] = a[i][j];
            x++;
        }
        x = 0;
        y--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=v[i][j];
        }
    } 
    
        // ans[j][n-1-i]=a[i][j];

    */
        // Transpose and reverse(swap every row)

        int n = a.size();
        int m = a[0].size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(a[i][j],a[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(a[i].begin(),a[i].end());
        }
    }
};
