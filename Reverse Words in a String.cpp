
// Problem Link -> https://leetcode.com/problems/reverse-words-in-a-string/


// Brute Force

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        stack<string> st;
        for(int i=0;i<n;i++){
            string a;
            if(s[i]!=' '){
                while(i<n && s[i]!=' '){
                    a+=s[i];
                    i++;
                }
            st.push(a);
            }
        }

        string ans=st.top();
        st.pop();
        while(!st.empty()){
            ans+=" "+st.top();
            st.pop();
        }
        return ans;
    }
};
