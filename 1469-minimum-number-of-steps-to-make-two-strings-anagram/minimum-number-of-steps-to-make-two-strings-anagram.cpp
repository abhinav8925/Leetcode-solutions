class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        map<char,int> m;

        for(int i=0;i<n1;i++){
            m[s[i]]++;
        }

        int ans=0;
        for(int i=0;i<n2;i++){
            if(m.find(t[i])!=m.end()){
                m[t[i]]--;
                if(m[t[i]] <= 0)
                    m.erase(t[i]);
            }
            else
                ans++;
        }

        return ans;
    }
};