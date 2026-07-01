class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int val, int col){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] == col || image[i][j]!=val) 
            return;
        
        image[i][j] = col;
        dfs(image, i-1,j,val,col);
        dfs(image, i+1,j,val,col);
        dfs(image, i,j-1,val,col);
        dfs(image, i,j+1,val,col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int col) {
        
        int val = image[sr][sc];
        dfs(image, sr, sc, val, col);
        return image;

    }
};