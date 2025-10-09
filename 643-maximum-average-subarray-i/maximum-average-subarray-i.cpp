// Using the prefix sum method

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        vector<double> p(nums.size(),0);
        p[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            p[i] = p[i-1] + nums[i];
        }

        double sum = p[k-1];
        double mx = sum;

        for(int i=1;i+k<=nums.size();i++){
            sum = p[i+k-1]-p[i-1];
            mx = max(mx,sum);
        }

        return mx/k;
    }
};


/*
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

        return mx/k;
    }
};

*/