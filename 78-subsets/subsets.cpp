class Solution {
public:
    void f(vector<int> &arr,int ind,vector<vector<int>> &ans,vector<int> &temp){

        ans.push_back(temp);
        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i] == arr[ind])    continue;
            temp.push_back(arr[i]);
            f(arr,i+1,ans,temp);
            temp.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        f(nums,0,ans,temp);

        return ans;

    }
};