class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        int p=n-k;
        vector<int> ans(n,0);

        for(int i=0;i<k;i++){
            ans[i] = nums[p++]; 
        }
        int j=0;
        for(int i=k;i<n;i++){
            ans[i] = nums[j++];
        }
        for(int i=0;i<n;i++){
            nums[i] = ans[i];
        }
    }
}; 