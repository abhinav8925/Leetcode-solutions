// Problem Link -> https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool check(int m1[],int m2[]){
        for(int i=0;i<26;i++){
            if(m1[i]!=m2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int m1[26]={0},m2[26]={0};
        for(int i=0;i<s1.size();i++)
            m1[s1[i]-'a']++;
        
        int i=0,win=s1.size();
        if(s1.size()>s2.size())
            return false;
        while(i<win){
            m2[s2[i]-'a']++;
            i++;
        }
        if(check(m1,m2))
                return true;
        
        while(i<s2.size()){
            m2[s2[i]-'a']++;
            
            // char x=s2[i-win];
            m2[s2[i-win]-'a']--;

            if(check(m1,m2))
                return true;
            
            i++;

        }

        return false;



    }
};