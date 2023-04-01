// Brute Force -> using nested loops
// Time Complexity -> O(n2)
// Space Complexity -> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};


// Better Approach -> Using Hashmaps
// Time Complexity -> O(n)
// Space Complexity -> O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(mp.find(target-num)!=mp.end())
            {
                return {i,mp[target-num]};
            }
            else
                mp[num]=i;
        }
        
        return {-1,-1};
    }
};


// optimized Approach -> Using Two pointers
// Time Complexity -> O(nlogn)
// Space Complexity -> O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int> nums2=nums;
        sort(nums.begin(),nums.end());

        for(int i=0,j=n-1;i<j;)
        {
            if(nums[i]+nums[j]>target)
                j--;
            else if(nums[i]+nums[j]<target)
                i++;
            else
                return {i,j};
        }
        return {-1,-1};
    }
};

