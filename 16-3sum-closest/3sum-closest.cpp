class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size(),r_ans = INT_MAX;
        int ans = INT_MAX;
    
        for(int i=0;i<n-2;i++){
            int l = i+1,r = n-1;

            while(l<r){
            int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return sum;
                }else if(sum > target)  r--;
                else    l++;
                
                int diff = 0;
                if((sum>=0 && target>=0) || (sum<=0 && target<=0))
                    diff = abs(abs(sum) - abs(target));
                else if(sum>=0 && target<0)
                    diff = sum+abs(target);
                else 
                    diff = abs(sum) + target;
                
                ans = min(ans,diff);
                if(ans == diff)
                    r_ans = sum; 
            }
        }

        return r_ans;

    }
};