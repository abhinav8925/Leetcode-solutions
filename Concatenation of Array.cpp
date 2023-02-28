class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> k=nums;
        for(int i=0;i<nums.size();i++)
        {
            k.push_back(nums[i]);
        }
        return k;
    }
};
