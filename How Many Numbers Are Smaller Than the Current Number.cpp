
// Problem Link -> https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/


// Brute Force

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(nums[i]>nums[j])
                        cnt++;
                }
            }
            v.push_back(cnt);
            cnt=0;
        }
        return v;
    }
};
