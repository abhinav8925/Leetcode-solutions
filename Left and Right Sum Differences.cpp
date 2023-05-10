// Problem Link ->  https://leetcode.com/problems/left-and-right-sum-differences/description/

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> left;
        vector<int> right(n);
        left.push_back(0);
        for(int i=1;i<n;i++)
        {
            int k=left[i-1]+nums[i-1];
            left.push_back(k);
        } 
        
        right[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int k=nums[i+1]+right[i+1];
            right[i]=(k);
            
        }
        
        
        vector<int> s;
        for(int i=0;i<n;i++)
            s.push_back(abs(left[i]-right[i]));
            
        return s;
        
    }
};
