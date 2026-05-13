class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), i=0,left=0;

        if(n1>n2)   return false;
        map<char,int> mp,mp2;
        for(int j=0;j<n1;j++)
            mp[s1[j]]++;
        
        for(;i<n1;i++){
            mp2[s2[i]]++;
        }

        if(mp == mp2)   return true;
        while(i<n2){
            mp2[s2[left]]--;
            if(mp2[s2[left]] == 0)  mp2.erase(s2[left]);
            mp2[s2[i++]]++;

            if(mp == mp2)   return true;
            left++;
        }
        return false;
    }
};