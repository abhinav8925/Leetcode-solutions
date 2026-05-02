class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i=0,j=0;
                
        for(;i<n;i++){
            if(nums[i]!=0){
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};