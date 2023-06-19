// Problem Link -> https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,n=gain.size();
        for(int i=1;i<n;i++){
            gain[i]+=gain[i-1];
            ans=max(ans,gain[i]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,gain[i]);
        }
        return ans;
    }
};
