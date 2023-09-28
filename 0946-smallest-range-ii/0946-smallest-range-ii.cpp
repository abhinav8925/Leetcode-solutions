// Problem Link -> https://leetcode.com/problems/smallest-range-ii/

class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {

        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int df = arr[n-1]-arr[0];
        
       
        
        int mxi ,mni;
        for(int i =0;i<n-1;i++){
            
            mxi = max(arr[i]+k,arr[n-1]-k);
            
            mni = min(arr[i+1]-k,arr[0]+k);
            
            df = min(df,mxi-mni);
            
        }
        return df;
        
        
    }
};