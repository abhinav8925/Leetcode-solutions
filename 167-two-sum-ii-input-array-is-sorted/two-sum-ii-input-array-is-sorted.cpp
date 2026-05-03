class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        int l = 0, r = n-1;
        while(l<r){
            int sum = numbers[l] + numbers[r];

            if(sum == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }else if(sum>target)    r--;
            else    l++;

        }
        return ans;
    }
};