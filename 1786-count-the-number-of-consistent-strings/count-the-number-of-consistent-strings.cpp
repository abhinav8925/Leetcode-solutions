// Problem Link -> https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> letter;
        for(int i=0; i<allowed.size(); i++)
            letter.insert(allowed[i]);
        int ans = words.size();
        for(auto word : words){
            for(auto i : word){
                if(letter.find(i) == letter.end()){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};