class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> mp;

        if (p.size() > s.size())
            return {};

        for(int i=0;i<p.size();i++)
            mp[p[i]]++;
        
        vector<int> ans;

        int left=0,right=0,n=s.size();
        map<char,int> m2;
        while(right<p.size()){
            m2[s[right]]++;
            right++;
        }

        if(mp == m2)    ans.push_back(left);
        
        while(right<n ){
            m2[s[left]]--;
            if(m2[s[left]] == 0)
                m2.erase(s[left]);
        
            m2[s[right]]++;
            right++;
            left++;
            
            if(mp == m2){
                ans.push_back(left);
            }
        }

       
        return ans;
    }
};