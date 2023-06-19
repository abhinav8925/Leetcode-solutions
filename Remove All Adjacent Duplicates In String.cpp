// Problem Link -> https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;
        string ans="";
        int n=s.size();
        st.push(s[0]);
        for(int i=1;i<n;){
            if(!st.empty() && st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
            
            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
