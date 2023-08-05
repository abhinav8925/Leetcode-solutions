// Problem Link -> https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        int n=nums.size();

        int till=pow(2,n)-1;
        
        for(int i=0;i<=till;i++){

            vector<int> v;
            for(int j=0;j<n;j++){
                if(i & (1<<j))
                    v.push_back(nums[j]);
            }

            if(v.size()>=0)
                ans.push_back(v);
        }

        
        sort(ans.begin(),ans.end());

        return ans;
        
    }
};
