// Problem Link -> https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ele=n+m-1;
        int cnt=0;
        
        vector<int> ans;
        int v=0;
        while(cnt<ele){
            
            if(cnt%2!=0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i+j == cnt)
                            ans.push_back(matrix[i][j]);
                    }
                }
            }
            else{
                vector<int> k;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i+j == cnt)
                            k.push_back(matrix[i][j]);
                    }
                }
                reverse(k.begin(),k.end());
                for(int o=0;o<k.size();o++)
                    ans.push_back(k[o]);
            }
            cnt++;
        }
        
        return ans;
    }
};
