class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        int n = nums.size();
        int i=0,j=0;
        vector<int> ans(n,0);

        stack<int> st;
      
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty())  ans[i]=0;
            else{
                ans[i] = st.top()-i;
            }
            st.push(i);
        }
        
        return ans;
    }
};