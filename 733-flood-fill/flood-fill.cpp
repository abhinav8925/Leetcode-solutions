class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        
        int incol = image[sr][sc];

        if(incol == color)
            return image;
        
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r+1 < n){
                if(image[r+1][c] == incol){
                    image[r+1][c] = color;
                    q.push({r+1,c});
                }
            }
            if(r-1 >= 0){
                if(image[r-1][c] == incol){
                    image[r-1][c] = color;
                    q.push({r-1,c});
                }
            }
            if(c+1 < m){
                if(image[r][c+1] == incol){
                    image[r][c+1] = color;
                    q.push({r,c+1});
                }
            }
            if(c-1 >= 0){
                if(image[r][c-1] == incol){
                    image[r][c-1] = color;
                    q.push({r,c-1});
                }
            }
        }

        return image;
    }
};