// Problem Link ->  https://leetcode.com/problems/add-to-array-form-of-integer/solutions/3188331/c-easy-to-understand/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int car=0;
        int sum=0;
        int i=nums.size()-1;

        while(k || car){
            sum=car+k%10;
            k/=10;

            if(i>=0){
                sum+=nums[i];
                nums[i]=sum%10;
                i--;
            }
            else{
                nums.insert(nums.begin(),sum%10);
            }
            car=sum/10;
        }

        return nums;
    }
};
