class Solution {
public:
    bool f(vector<vector<char>> &board, int ind, int i, int j,vector<vector<char>> &vis, string word){

        if(ind == word.size()){
            return true;
        }
        if(i>=board.size() || i<0 || j>=board[i].size() || j<0)
            return false;
        
        if(!vis[i][j]){
            if(word[ind] == board[i][j]){
                vis[i][j] = true;
                if(f(board,ind+1,i+1,j,vis,word) || f(board,ind+1,i-1,j,vis,word))
                    return true;

                if(f(board,ind+1,i,j-1,vis,word) || f(board,ind+1,i,j+1,vis,word))
                    return true;
                vis[i][j]=false;
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int ind=0;
        vector<vector<char>> vis(board.size(), vector<char>(board[0].size(), false));
        

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[ind]){
                    string temp="";
                    if(f(board,ind,i,j,vis,word))
                        return true;
                }
            }
        }

        return false;
    }
};