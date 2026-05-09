class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n; 
        int i=0,j=n-k-1;

        for(;i<j;){
            swap(nums[i++],nums[j--]);
        }
        i=n-k,j=n-1;
        for(;i<j;){
            swap(nums[i++],nums[j--]);
        }

        for(int i=0,j=n-1;i<j;i++,j--)  swap(nums[i],nums[j]);
    }
}; 