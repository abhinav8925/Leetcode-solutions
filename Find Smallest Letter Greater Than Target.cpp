// Problem Link ->  https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char a='{';
        

        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                a=min(letters[i],a);
            }
        }

        if(a=='{')
            return letters[0];
        return a;
    }
};
