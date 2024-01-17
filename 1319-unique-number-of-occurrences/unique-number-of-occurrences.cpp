class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        map<int, int> m;
        for(int i=0;i<a.size();i++)
        {
            m[a[i]]++;
        }
        bool ans=true;

        set<int> s;
        for(auto &it:m)
        {
            s.insert(it.second);
        }

        if(s.size()==m.size())
            return true;
        else
            return false;
            
     }
};