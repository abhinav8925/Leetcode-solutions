class Solution {
public:
    void f(int ind, vector<int> nums, vector<vector<int>> &ans, vector<int> &temp
    ,int &sum, int n,int k){

        if(sum == n && temp.size() == k){
            ans.push_back(temp);
            return;
        }

        if(ind == 9)
            return;
        
        if(nums[ind] + sum <= n){
            temp.push_back(nums[ind]);
            sum+=nums[ind];
            f(ind+1,nums,ans,temp,sum,n,k);
            sum-=nums[ind];
            temp.pop_back();
        }
        f(ind+1,nums,ans,temp,sum,n,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;

        int ind=0,sum=0;
        f(ind,nums,ans,temp,sum,n,k);

        return ans;
    }
};