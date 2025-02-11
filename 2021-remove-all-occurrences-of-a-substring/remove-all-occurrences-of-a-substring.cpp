// Problem  Link -> https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()!=0 && s.find(part)!=string::npos){
            s.erase(s.find(part),part.size());
        } 
        return s;
    }
};