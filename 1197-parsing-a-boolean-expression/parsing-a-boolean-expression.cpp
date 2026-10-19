class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;

        int i=0;
        while(i<n){
            if (s[i] == '!' || s[i] == '&' || s[i] == '|' ||
                    s[i] == 't' || s[i] == 'f') {
                    st.push(s[i]);
                }
              
            else if(s[i] == ')'){
                char op;
                bool t=false,f=false;
                while(!st.empty()){
                    if (st.top() == '&' || st.top() == '|' || st.top() == '!'){
                        op = st.top();
                        st.pop();
                        break;
                    }else{
                        if(st.top() == 't'){
                            t = true;
                            st.pop();
                        }
                        else if(st.top() == 'f'){
                            f = true;
                            st.pop();
                        }
                    }
                }
                if(op == '&'){
                    if(t && !f)
                        st.push('t');
                    else
                        st.push('f');
                }
                if(op == '|'){
                    if(!t)
                        st.push('f');
                    else
                        st.push('t');
                }
                if (op == '!') {
                    if (t) st.push('f');
                    else   st.push('t');
                }
                
                
            }
            i++;
        }
        return st.top() == 't';
    }
};