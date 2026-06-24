class Solution {
public:

    bool f(int mid, vector<int> &nums, int m, int k){

        int n = nums.size();
        int temp=0, cnt=0;

        for(int i=0;i<n;i++){
            if(cnt >= m) return true;
            
            if(nums[i]<=mid){
                temp++;
            }else{
                temp=0;
            }
            if(temp == k){
                    cnt++;
                    temp=0;
            } 
        }

        return cnt>=m ? true : false;
    }
    int minDays(vector<int>& nums, int m, int k) {
        

        int n = nums.size();
        if((long)m*k > n) return -1;

        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        int ans = -1;

        while(low<=high){

            int mid = low + (high-low)/2;
            if(f(mid, nums, m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};