class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n = num.size();
        if(k>=n)
            return "0";
        if(k==0)
            return num;
        
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(k>0 && !st.empty() && num[i]<st.top()){
                --k;
                st.pop();
            }
            st.push(num[i]);

            if(st.size()==1 && num[i]=='0')
                st.pop();
        }

        while(k && !st.empty())
        {
            
            --k;
            st.pop();
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top()); 
            st.pop(); 
        }
        
        reverse(ans.begin(),ans.end());  
        
        if(ans.length() == 0)
            return "0";
        
        return ans;
    }
};