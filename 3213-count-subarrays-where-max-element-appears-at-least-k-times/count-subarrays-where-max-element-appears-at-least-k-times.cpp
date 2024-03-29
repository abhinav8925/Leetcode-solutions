#define ll long long int
#include<bits/stdc++.h>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        ll mx =0 ;
        ll n = nums.size();
        for(ll i=0;i<n;i++){
            if(nums[i]>mx)
                mx = nums[i];
        }

        ll left = 0,right=0,ans=0,cnt=0;

        while(right<n){
            if(nums[right]==mx)
                cnt++;
            while(cnt>=k){
                ans+=(n-right);
                if(nums[left]==mx)
                    cnt--;
                
                left++; 
                               
            }
            
            
            right++;
        }

        return ans;
    }
};