class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        if(n%2!=0)
            return 0;
        
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            if(st.size()>0)
            {
                if(s[i]==')')
                {
                    if(st.top()=='(')
                        st.pop();
                    else 
                        return 0;
                }
                else if(s[i]==']')
                {
                    if(st.top()=='[')
                        st.pop();
                    else 
                        return 0;
                }
                else if(s[i]=='}')
                {
                    if(st.top()=='{')
                        st.pop();
                    else
                        return 0;
                }
            }
            else if(st.size()<=0)
                return 0;
            
        }
        if(st.size()==0)
            return 1;
        else
            return 0;
    }
};
