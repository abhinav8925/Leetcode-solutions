class Solution {
public:
    vector<int> findAnagrams(string s, string s2) {
        map<char,int> m1,m2;
         for(char c:s2) m1[c]++;
          vector<int> v; 
          int i=0;
          for(int j=0;j<s.size();j++){
             m2[s[j]]++; 
             if(j-i+1 == s2.size()){ 
                if(m1 == m2){ 
                    v.push_back(i); 
                    } 
                m2[s[i]]--;
                 if(m2[s[i]] == 0) m2.erase(s[i]);
                  i++; 
            }
         } 
         return v;
    }
};