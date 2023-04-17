class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
        int mx=0;
        for(int i=0;i<candies.size();i++)
            mx=max(candies[i],mx);
        
        vector<bool> v;
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+ec)>=mx)
                v.push_back(true);
            else
                v.push_back(false);
       }
       return v;
    }
};
