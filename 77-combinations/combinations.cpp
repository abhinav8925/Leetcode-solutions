class Solution {
public:
    void f(int start,int n,int k,vector<vector<int>> &res,vector<int> &temp){

        if(temp.size()==k){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++){
            temp.push_back(i);
            f(i+1,n,k,res,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        
        
        vector<vector<int>> res;
        vector<int> temp;

         f(1,n,k,res,temp);
         return res;
    }
};