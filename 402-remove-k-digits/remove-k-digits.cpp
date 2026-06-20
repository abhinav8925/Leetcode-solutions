class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char> st;
        int n = s.size();

        if(k>=n)    return "0";

        for(int i=0;i<n;i++){
               
            while(!st.empty() && (st.top() - '0') > (s[i]-'0') && k>0){
                st.pop();
                k--;
            }

            st.push(s[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string ans = "";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        int i=0;
        string ans2="";
        while(i<ans.size() && ans[i] =='0'){
            i++;
        }

        // cout << i << endl;
        if(i>=ans.size())    return "0";

        for(int j=i;j<ans.size();j++)
            ans2+=ans[j];

        return ans2;
    }
};