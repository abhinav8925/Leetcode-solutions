class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0,r=n-1;

        for(int i=0;i<n;i++){
            int area = min(height[l],height[r])*(r-l);

            if(height[l]<=height[r]) l++;
            else    r--;

            ans = max(ans,area);
        }

        return ans;
    }
};