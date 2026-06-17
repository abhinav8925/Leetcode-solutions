class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int> ans;
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()] <= nums2[i])
                st.pop();
            
            if(st.size()==0)   ans[nums2[i]] = 0;
            else
                ans[nums2[i]] = nums2[st.top()];
            
            st.push(i);

        }

        vector<int> ans2;
        for(int i=0;i<nums.size();i++){
            if(ans.find(nums[i])!=ans.end()){
                if(ans[nums[i]] == 0)
                    ans2.push_back(-1);
                else
                    ans2.push_back(ans[nums[i]]);
            }
        }

        return ans2;
    }
};