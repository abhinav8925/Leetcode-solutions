// Problem Link -> https://leetcode.com/problems/rotate-array/

// Brute Force Approach -> Shift the array by one place k times

// class Solution {
// public:
//     void rotate(vector<int>& a, int k) {
//         int n=a.size();
//         k=k%n;

//         for(int j=1;j<=k;j++)
//         {
//             int temp=a[n-1];
//             for(int i=n-1;i>=1;i--)
//             {
//                 a[i]=a[i-1];
//             }
//             a[0]=temp;
//         }


        
//     }
// };

//Better Approach -> Use another  array for storing the elements and after rotation copy the elements to the original array

// class Solution {
// public:
//     void rotate(vector<int>& a, int k) {
//         int n=a.size();
//         k=k%n;

//         vector<int> v(n);

//         for(int i=0;i<n;i++)
//         {
//             v[(i+k)%n]=a[i];
//         }
//         for(int i=0;i<n;i++)
//             a[i]=v[i];
//     }
// };


// Optimal Approach  -> Inplace rotating the elements;


class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;

        for(int i=0,j=n-1;i<j;i++,j--)
            swap(a[i],a[j]);
        for(int i=0,j=k-1;i<j;i++,j--)
            swap(a[i],a[j]);
        for(int i=k,j=n-1;i<j;i++,j--)
            swap(a[i],a[j]);

    }
};

