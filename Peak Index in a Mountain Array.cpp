// Problem Link -> https://leetcode.com/problems/peak-index-in-a-mountain-array/

// brute force

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int mx=-2;
//         int n=arr.size();
//         for(int i=0;i<n;i++)
//             mx=max(mx,arr[i]);
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             if(mx==arr[i])
//                 {
//                     ans=i;
//                     break;
//                 }
//         }
//         return ans;
//     }
// };


// optimal 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int s=0,e=n-1;
        
        while(s<e)
        {
            int mid=(s+e)/2;
            if(a[mid]>a[mid+1])
            {
                e=mid;
            }
            else if(a[mid]<a[mid+1])
                s=mid+1;
        }
        return s;
    }
};
