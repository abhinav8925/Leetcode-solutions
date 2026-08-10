class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        

        unordered_map<int,int> freq;
        
        
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        
        vector<vector<int>> buc(n+1);
        

        for(auto &it: freq){
            buc[it.second].push_back(it.first);
        }

        vector<int> ans;

        
        for(int i=buc.size()-1;i>=0;i--){
            for(int j=0;j<buc[i].size();j++){
                if(k==0)    return ans;
                ans.push_back(buc[i][j]);
                k--;
            }
        }

        return ans;


        
    }
};