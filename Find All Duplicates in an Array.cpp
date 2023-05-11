// Problem Link -> https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Brute Force
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
        
//         vector<int> v;
//         map<int,int> m;
        
//         for(int i=0;i<nums.size();i++)
//         {
//            m[nums[i]]++;
//         }
//         for(auto &it :m)
//         {
//             if(it.second==2)
//                 v.push_back(it.first);
//         }
//         return v;
//     }
// };


// Better -> to use a hashmap 

// better -> to use a 2 array

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
        
//         vector<int> v;
//         int n=nums.size();
//         vector<int> b(n+1,0);
//         for(int i=0;i<n;i++)
//         {
//             b[nums[i]]++;
//         }
//         for(int i=0;i<n+1;i++)
//         {
//             if(b[i]>1)
//                 v.push_back(i);
//         }
//         return v;
//     }
// };

// Optimal 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ind=abs(nums[i])-1;
            if(nums[ind]<0)
                v.push_back(abs(nums[i]));
            else
                nums[ind]=-nums[ind];
                
        }
        return v;
    }
};




















