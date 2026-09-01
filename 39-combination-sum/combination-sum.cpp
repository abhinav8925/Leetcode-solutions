class Solution {
public:
    void f(vector<int> arr,int ind, int n, int &target, int &sum, vector<vector<int>> &ans, vector<int> &temp){

        if(sum == target){
                 ans.push_back(temp);
                 return;
        }
        
        if(ind == n)
            return;

        if(sum + arr[ind] <= target){
            sum+=arr[ind];
            temp.push_back(arr[ind]);
            f(arr,ind,n,target,sum,ans,temp);
            sum-=arr[ind];
            temp.pop_back();
        }
        f(arr,ind+1,n,target,sum,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        int st=0,n=arr.size(),sum=0;
        f(arr,st,n,target,sum,ans,temp);

        return ans;
    }
};