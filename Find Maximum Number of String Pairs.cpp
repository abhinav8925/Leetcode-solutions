// Problem Link ->  https://leetcode.com/contest/biweekly-contest-107/problems/find-maximum-number-of-string-pairs/


class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& s) {
        
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            string k=s[i];
            bool ans=true;
            for(int j=i+1;j<s.size();j++){
                string u=s[j];
                reverse(u.begin(),u.end());
                if(k==u)
                    cnt++;
            }
        }
        
        return cnt;
    }
};
