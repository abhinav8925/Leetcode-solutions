class Solution {
public:
    bool isletter(char c){
        if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        
        int n = s.size();
        int l = 0, r = n-1;

        while( l <= r){
            if(isletter(s[l]) && isletter(s[r])){
                s[l] = tolower(s[l]);
                s[r] = tolower(s[r]);
                if(s[l] == s[r]){
                    l++;
                    r--;
                }else{
                    return false;
                }
            }
            else if(isletter(s[l])==false)
                l++;
            else if(isletter(s[r])==false)
                r--;
        }
        return true;
    }
};