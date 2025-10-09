class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum = 0;
        for(int i=0;i<k;i+=1)
            sum+=nums[i];
        
        double mx = sum;
        int j=0;
        for(int i=k;i<nums.size();i+=1){

            sum+=nums[i];
            sum-=nums[j++];
            mx = max(mx,sum);
        }

        return max(mx,sum)/k;
    }
};