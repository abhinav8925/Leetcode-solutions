// Problem Link -> https://leetcode.com/problems/rotate-image/description/


// using extra space (brute force)

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
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
    }
};
