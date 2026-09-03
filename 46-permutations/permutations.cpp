class Solution {
public:
    void f(int ind, vector<int> &nums,vector<vector<int>> &ans){
        if(ind == nums.size()){
            vector<int> temp;
            for(int i=0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            f(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        f(0,nums,ans);

        return ans;
    }
};