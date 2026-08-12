class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        

        int rs=0,re=2,cs=0,ce=2;
        for(int p=0;p<3;p++){
            for(int l=0;l<3;l++){
                map<char,int> mp;
                for(int i=rs;i<=re;i++){
                    for(int j=cs;j<=ce;j++){
                        if(board[i][j] == '.')  continue;
                        mp[board[i][j]]++;
                        if(mp[board[i][j]]>1)  return false;
                    }
                }
                cs+=3;
                ce+=3;
            }
            rs+=3;
            re+=3;
            cs=0;
            ce=2;
        }

        

        // row checking 
        for(int i=0;i<9;i++){
            map<char,int> m1;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')  continue;
                m1[board[i][j]]++;
                if(m1[board[i][j]]>1)  return false;
            }
        }

        // column checking
        for(int j=0;j<9;j++){
            map<char,int> m2;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.')  continue;
                m2[board[i][j]]++;
                if(m2[board[i][j]] >1) return false;
            }
        }

        return true;

    }
};