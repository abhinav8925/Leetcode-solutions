// Problem Link -> https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

            stack<int> st;

            int i=0;
            for(int j=0;j<pushed.size();j++){
                st.push(pushed[j]);

                while(!st.empty() && st.top() == popped[i] ){
                    i++;
                    st.pop();
                }
            }

            if(i==popped.size())
                return 1;
            return 0;

        
    }
};