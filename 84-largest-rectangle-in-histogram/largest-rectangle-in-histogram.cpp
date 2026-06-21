class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> st;
        vector<int> prev(n),next(n);

        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            
            if(st.size() == 0) prev[i] = -1;
            else    prev[i] = st.top();

            st.push(i);
        }

        while(!st.empty())  st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.size() == 0)  next[i] = n;
            else    next[i] = st.top();

            st.push(i);
        }
        

        int ans = 0;

        for(int i=0;i<n;i++){
            int height = nums[i];
            int dis = -prev[i]+next[i]-1;
            int area = height * dis;
            ans = max(ans,area);
        }

        return ans;
    }
};