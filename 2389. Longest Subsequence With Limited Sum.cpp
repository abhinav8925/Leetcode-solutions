// Problem Link -> https://leetcode.com/problems/longest-subsequence-with-limited-sum/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& a) {

        int n=nums.size();
        int m=a.size();
        
        sort(nums.begin(),nums.end());
        int sum=0;

        vector<int> pre_sum;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            pre_sum.push_back(sum);
        }

        vector<int> ans(m,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pre_sum[j] <= a[i])
                    ans[i]=j+1;
                else
                    break;
            }
        }
        
        return ans;
    }
};
