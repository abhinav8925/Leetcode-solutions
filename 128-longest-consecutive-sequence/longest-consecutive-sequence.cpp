class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        
        int cnt = 0,ans=0;
        for(auto it: st){
            int ele = it;
            if(st.find(ele-1) == st.end()){
                int cur = ele;
                cnt = 1;
                while(st.find(cur+1) != st.end()){
                    cur++;
                    cnt++;
                }
            }

            ans = max(ans,cnt);
        }

        return ans;
    }
};