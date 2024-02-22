// Problem Link -> https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        
        map<int,int> m;

        if(n==1 && a.size()==0)
            return 1;

        for(int i=0;i<a.size();i++){
            int k1=a[i][0],k2=a[i][1];

            m[k1]--;
            m[k2]++;
        }

        int mx=0;
        for(auto it:m){
            if(it.second==n-1)
                return it.first;
        }

        return -1;

        
    }
};