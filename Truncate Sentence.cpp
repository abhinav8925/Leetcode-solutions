// Problem Link -> https://leetcode.com/problems/truncate-sentence/

class Solution {
public:
    string truncateSentence(string s, int k) {

        int n=s.size(),cnt=1,sp=1;
        string ans="";
        bool as=true;
        for(int i=0;i<n;i++){
            if(sp>k){
                as=false;
                break;
            }
            if(s[i]!=' ')
                ans+=s[i];
            else if(s[i]==' '){
                ans+=' ';
                sp++;
            }
        }
        if(as)
            return ans;
        else{
         ans.pop_back();
        }
         return ans;
    }
};
