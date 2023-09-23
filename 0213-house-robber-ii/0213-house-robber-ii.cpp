// Problem Link -> https://leetcode.com/problems/house-robber-ii/

class Solution {
public:

    int f(vector<int> &v){

        int prev=v[0];
        int prev2=0;

        for(int i=1;i<v.size();i++){
            int t = v[i];
            if(i>1)
                t+=prev2;
            int nt = 0 + prev;

            int cur = max(t,nt);

            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        

        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        

        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(f(v1),f(v2));
    }
};