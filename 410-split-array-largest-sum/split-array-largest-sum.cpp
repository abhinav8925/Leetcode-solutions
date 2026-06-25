class Solution {
public:

    bool f(int mid, int k, vector<int> &nums){

        int cnt = 1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum+=nums[i];
            }else{
                cnt++;
                sum=nums[i];
            }
        }

        return cnt<=k ? true : false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);

        int ans = h;

        while(l<=h){
            int m = l+ (h-l)/2;

            if(f(m,k,nums)){
                ans = m;
                h = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }
};