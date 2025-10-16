class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(256,0);
        int r=0,l=0,cnt=0,ml=INT_MAX,sid=-1,n=s.size();

        for(int i=0;i<t.size();i++) v[t[i]]++;

        while(r<n){
            if(v[s[r]]>0)   cnt++;
            v[s[r]]--;

            while(cnt == t.size()){
                if(r-l+1 < ml){
                    ml = r-l+1;
                    sid = l;
                }
                v[s[l]]++;
                if(v[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sid == -1 ? "" : s.substr(sid, ml);
    }
};