// Problem Link -> https://leetcode.com/problems/separate-the-digits-in-an-array/

class Solution {
public:
    vector<int> separateDigits(vector<int>& a) {
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) {
            int k=a[i];
            vector<int>  v;
            while(k>0){
                v.push_back(k%10);
                k/=10;
            }  

            for(int j=v.size()-1;j>=0;j--)
                ans.push_back(v[j]);
        }
        return ans;
    }
};
