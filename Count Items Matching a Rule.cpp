// Problem Link -> https://leetcode.com/problems/count-items-matching-a-rule/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
            int cnt=0,k;
            if(ruleKey=="type")
                k=0;
            else if(ruleKey=="color")
                k=1;
            else
                k=2;
        int rows=items.size();
        for(int i=0;i<rows;i++){
            
            for(int j=0;j<3;j++){
                if(items[i][k]==ruleValue)
                    cnt++;
                    break;
            }
        }
        return cnt;
    }
};
