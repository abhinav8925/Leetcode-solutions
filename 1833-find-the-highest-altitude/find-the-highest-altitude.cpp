class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,mn=INT_MIN;
        for(int i=0;i<gain.size();i++){
            mn = max(ans,mn);
            ans+=gain[i];
        }
        return max(mn,ans);
    }
};