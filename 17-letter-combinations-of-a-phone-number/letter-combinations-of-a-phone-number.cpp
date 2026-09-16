class Solution {
public:
    void f(int ind, string &temp, vector<string> &ans, map<char,string> &mp,string s){

        if(temp.size() == s.size()){
            ans.push_back(temp);
            return;
        }
        
         string temp2 = mp[s[ind]];
        for(int k=0;k<temp2.size();k++){
                temp+=temp2[k];
                f(ind+1,temp,ans,mp,s);
                temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string s) {
        map<char,string> mp;
        int n = s.size();

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        

        vector<string> ans;
        string temp="";

        f(0,temp,ans,mp,s);
        return ans;
    }
};