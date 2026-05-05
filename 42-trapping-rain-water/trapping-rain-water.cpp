class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n-1;
        int ans = 0, mxl=height[0],mxr=height[n-1];

        while(l<r){
            int water = 0;
            if(height[l] < height[r]){
                mxl = max(mxl,height[l]);
                water = mxl - height[l];
                l++;
            }else{
                mxr = max(mxr,height[r]);
                water = mxr - height[r];
                r--;
            }
            
            ans+=water;
        }
        return ans;
    }
};