// Problem Link -> https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    void comb(int ind, int n, int target, vector<int> &ds, vector<int> &a, vector<vector<int>> &ans) {
    
        if (target == 0 ) {
            ans.push_back(ds);
            return;
        }
    
    

    for(int i=ind;i<n;i++){
        if(i>ind && a[i]==a[i-1])
            continue;
        
        if(a[i]>target)
            break;
        
        ds.push_back(a[i]);
        comb(i+1, n, target - a[i], ds, a, ans);
        ds.pop_back();
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& a, int target) {
    int n = a.size();
    vector<int> ds;

    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    

    comb(0, n, target, ds, a, ans);

    return ans;
}

};