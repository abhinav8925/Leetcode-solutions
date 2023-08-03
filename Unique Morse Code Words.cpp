// Problem Link -> https://leetcode.com/problems/unique-morse-code-words/description/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<string,int> um;

        for(int i=0;i<words.size();i++){
            string ans;
            for(int j=0;j<words[i].size();j++){
                ans+=a[words[i][j]-'a'];
            }
            um[ans]=1;
        }

        return um.size();
    }
};
