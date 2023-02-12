class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        
        while(l<=r)
        {
           int mid = (l+r)/2;
            
            if  (nums[mid]==target)
                return mid;
            else if (target > nums[mid])
                l = mid+1;
            else if(target <nums[mid])
                r = mid-1;
         }
        return l;
    }
};
