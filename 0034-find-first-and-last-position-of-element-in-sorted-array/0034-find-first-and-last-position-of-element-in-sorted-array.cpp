class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=0;
        int l=0;
        f=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        l=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

        vector<int> v;
        if((f!=nums.size() && nums[f]==target) && (--l!=nums.size() && nums[l]==target))
            {
                v.push_back(f);
                v.push_back(l);
            }
        else 
            {
                v.push_back(-1);
                v.push_back(-1);
            }
        return v;
    }
};