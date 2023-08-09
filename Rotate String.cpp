// Problem Link -> https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size()==goal.size()){
            string ans=s+s;

            if(ans.find(goal)!=string::npos)
                return true;
            return false;
        }
        return false;
    }
};
