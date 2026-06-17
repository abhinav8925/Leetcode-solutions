class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        int n2 = 2*n;

        vector<int> nums2(n2,0);
        int i=0;
        for(i=0;i<n;i++)
            nums2[i] = nums[i];
        
        int j=0;
        for(;i<n2;i++){
            nums2[i]=nums[j++];
        }

        // for(int i=0;i<n2;i++)   cout << nums2[i] << " ";

        // cout << endl;

        vector<int> ans(n2,-1);

        stack<int> st;
        
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()] <= nums2[i])
                st.pop();
            
            if(st.size() == 0)  ans[i] = -1;
            else    ans[i] = nums2[st.top()];

            st.push(i);
        }

        vector<int> ans2;
        for(int i=0;i<n;i++)    
            ans2.push_back(ans[i]);
        
        for(int i=0;i<n2;i++)   cout << ans[i] << " ";

        cout << endl;
        return ans2;
        
    }
};