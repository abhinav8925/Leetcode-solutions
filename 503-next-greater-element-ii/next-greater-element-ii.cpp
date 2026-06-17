class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        int n2 = 2*n;

        

        stack<int> st;
        vector<int> ans(n,-1);
        
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums[st.top()%n] <= nums[i%n])
                st.pop();
            
            if(st.size() == 0)  ans[i%n] = -1;
            else    ans[i%n] = nums[st.top()%n];

            st.push(i);
        }

        return ans;
        
    }
};