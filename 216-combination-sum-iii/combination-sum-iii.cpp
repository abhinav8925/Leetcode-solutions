class Solution {
public:
    void f(vector<vector<int>> &ans,vector<int> &temp,int sum,int cnt,int ind){

        if(cnt==0){
            if(sum==0){
                ans.push_back(temp);
                return;
            }
        }
        if(ind>9)
            return;
        if(sum<0 || cnt<0)
            return;
        
        temp.push_back(ind);
        f(ans,temp,sum-ind,cnt-1,ind+1);
        temp.pop_back();
        f(ans,temp,sum,cnt,ind+1);

        
        


    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;
        f(ans,temp,n,k,1);

        return ans;
    }
};