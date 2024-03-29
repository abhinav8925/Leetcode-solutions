class Solution {
public:

    int compute(string &t1, string &t2){
        int h1 = (t1[0] - '0')*10 + (t1[1] - '0');
        int h2 = (t2[0] - '0')*10 + (t2[1] - '0');
        int m1 = (t1[2] - '0')*10 + (t1[3] - '0');
        int m2 = (t2[2] - '0')*10 + (t2[3] - '0');

        if(h1==h2)
            return m2-m1;
        else if(h2-h1==1)
            return 60-(m1-m2);
        return 200;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        int n = at.size();
        vector<string> ans;

        unordered_map<string,vector<string>> m;
        for(auto at:at){
            m[at[0]].push_back(at[1]);
        }

        
        for(auto itr:m){
            if(itr.second.size()>=3){
                sort(itr.second.begin(),itr.second.end());
                for(int i=2;i<itr.second.size();i++){
                    if(compute(itr.second[i-2],itr.second[i])<60){
                        ans.push_back(itr.first);
                        break;
                    }
                }

            }
        }

        return ans;
    }
};