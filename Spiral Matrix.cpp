// Problem Link -> https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {

       int row=m.size();
       int col=m[0].size();

       int sr=0;
       int sc=0;
       int er=row-1;
       int ec=col-1;

       int ele=row*col;
       int cnt=0;

       vector<int> v;
       while(cnt<ele){

           for(int i=sc;i<=ec && cnt<ele;i++){
                v.push_back(m[sr][i]);
                cnt++;
           }
           sr++;

           for(int i=sr;i<=er && cnt<ele;i++){
               v.push_back(m[i][ec]);
               cnt++;
           }
           ec--;

           for(int i=ec;i>=sc && cnt<ele;i--){
                v.push_back(m[er][i]);
                cnt++;
           }
           er--;

           for(int i=er;i>=sr && cnt<ele;i--){
               v.push_back(m[i][sc]);
               cnt++;
           }
           sc++;
             
       }
        
        return v;
        
    }
};
