class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i=0,j=0;
        while(i<n-1 && nums[i] == 0 && nums[i] == nums[i+1])
            i++;
        
        for(;i<n;i++){
            if(nums[i]!=0){
                swap(nums[j], nums[i]);
                j++;
            }
            while(i<n-1 && nums[i] == 0 && nums[i] == nums[i+1])
                i++;
        }
    }
};