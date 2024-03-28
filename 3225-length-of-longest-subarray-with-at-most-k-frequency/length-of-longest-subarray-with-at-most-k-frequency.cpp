class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n =nums.size();
        unordered_map<int,int> m;

                
        int left=0,right=0,cnt=0;

        while(left<n && right<n){
            m[nums[right]]++;
            
                while(m[nums[right]]>k){
                    
                    m[nums[left]]--;
                    left++;
                }
            cnt = max(cnt,right-left+1);
            right++;
        }

        return cnt;
    }
};