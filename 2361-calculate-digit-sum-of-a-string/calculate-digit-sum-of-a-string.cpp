// Problem Link -> https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {
        vector<int> ans;
        int num=0;


        while(s.size()>k){
            for(int i=0;i<s.size();i++){
                num=0;
                for(int j=0;j<k;j++){
                    if(i<s.size()) 
                    num=num+s[i]+'0'-96;
                    i++;
                }
            i--;
            ans.push_back(num);
        }
        s.clear();
        for(int i=0;i<ans.size();i++){
            s=s+to_string(ans[i]); 

        }
    
        ans.clear();
        }
        return s;
    }
};