class Solution {
public:
    void f(int ind, vector<int> arr, int target, vector<vector<int>> &ans, vector<int> &temp){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i] == arr[i-1])
                continue;
            
            if(arr[i] > target)
                break;
            
            temp.push_back(arr[i]);
            f(i+1,arr,target-arr[i],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        f(0,arr,target,ans,temp);
        return ans;
    }
};