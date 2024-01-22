class Solution {
public:
    vector<int> ans;
    Solution(vector<int>& nums) {
        ans=nums;
    }
    
    int pick(int target) {
        
        int n = size(ans);
        int random = rand()%n;
        while(ans[random]!=target)
            random = rand()%n;
        
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */