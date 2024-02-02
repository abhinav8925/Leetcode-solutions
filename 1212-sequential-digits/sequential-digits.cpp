
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        

        string sol = "123456789";
        vector<int> ans;
        for(int i=0;i<9;i++){
            for(int j=i+1;j<9;j++){
                int num  = stoi(sol.substr(i,j-i+1));
                if(num>high)
                    break;
                if(num>=low)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};