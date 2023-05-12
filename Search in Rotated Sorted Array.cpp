// Problem Link -> https://leetcode.com/problems/search-in-rotated-sorted-array/

// Brute Force

// class Solution {
// public:

//     int search(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++)
//         {
//                 if(nums[i]==target)
//                     return i;
//         }
//         return -1;
//     }
// };


// Optimal

 class Solution {
public:
    int bs(vector<int> a,int st,int en, int key)
    {
        int s=st;
        int e=en;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(a[mid]==key)
            {
                return mid;
            }
            else if(a[mid]>key)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
    int piv(vector<int> &a,int n)
    {
        
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<e)
        {

            if(a[mid]>=a[0])
                s=mid+1;
            else
                e=mid;
            
            mid=(s+e)/2;
        }
        
        return s;
    }


    int search(vector<int>& a, int key) {
    int n=a.size();
    int pivot=piv(a,n);
    if(key>=a[pivot] && key<=a[n-1])
        return bs(a,pivot,n-1,key);
    
    return bs(a,0,pivot-1,key);
   
    }
};
