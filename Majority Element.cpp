// Problem Link-> https://leetcode.com/problems/majority-element/

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int> m;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//             m[nums[i]]++;
        
//         n=n/2;
//         int ans=0,ans2=0;
//         for(auto &it:m){
//             if(it.second>n)
//                 return it.first;
//         }
        
//         return 0;
//     }
// };


// Optimal ->   moore voting algo

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int cnt=1;
        int ele=a[0];

        int n=a.size();

        for(int  i=1;i<n;i++){
            
            if(cnt==0)
                ele=a[i];
            if(a[i]==ele)
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};
