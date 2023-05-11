
// Problem Link -> https://leetcode.com/problems/find-the-duplicate-number/description/

// Brute Force
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int,int> mp;
//         for(int i=0;i<nums.size();i++)
//             mp[nums[i]]++;
        
//         int ans=0;
//         for(auto &it:mp)
//             if(it.second>1)
//                 return it.first;
//     }
// };

// Better 

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ans=0;
//         sort(nums.begin(),nums.end());

//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 ans=nums[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };

// Optimal

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=nums[0];
        int right=nums[0];
        do{
            left=nums[left];
            right=nums[nums[right]];
        }while(left!=right);

        right=nums[0];

        while(left!=right)
        {
            left=nums[left];
            right=nums[right];
        }

        return right;
        
        
        
    }
};
