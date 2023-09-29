// Problem Link -> https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
         bool isIncreasing = true; 
        bool isDecreasing = true; 

        
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] < nums[i - 1])
                isIncreasing = false;
                
            
            else if (nums[i] > nums[i - 1])
                isDecreasing = false;

            
            if (!isIncreasing && !isDecreasing)
                break;
        }

        return isIncreasing || isDecreasing;
    }
};