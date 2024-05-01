// Problem Link -> https://leetcode.com/problems/reverse-prefix-of-word/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();

        int pos=word.find(ch);
        string ans="";
        for(int i=0,j=pos;i<j;i++,j--){
            swap(word[i],word[j]);
        }

        return word;    
        
    }
};