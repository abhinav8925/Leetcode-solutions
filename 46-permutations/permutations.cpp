class Solution {
public:
    void f(int ind, vector<int> &nums, vector<int> &temp, vector<bool> &mp, vector<vector<int>> &ans){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(mp[i] == false){
                mp[i] = true;
                temp.push_back(nums[i]);
                f(i,nums,temp,mp,ans);
                mp[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<bool> mp(nums.size(),false);
        int ind=0;
        vector<int> temp;

        f(ind,nums,temp,mp,ans);

        return ans;
    }
};