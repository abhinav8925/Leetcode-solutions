class Solution {
public:
    void f(int ind, string &temp, vector<string> &ans, long long target,long long val, long long prev, string num){

        if(ind == num.size()){
            if(val == target){
                ans.push_back(temp);
            }
            return;
        }

        long long cur = 0;
        for(int i=ind;i<num.size();i++){

            if(i>ind && num[ind] == '0')
                break;
            
            cur = cur *10 + (num[i] - '0');

            int sz = temp.size();

            if(ind == 0){
                temp+=num.substr(ind,i-ind+1);
                f(i+1,temp,ans,target,cur,cur,num);
                temp.resize(sz);
            }else{
                temp+="+" + num.substr(ind,i-ind+1);
                f(i+1,temp,ans,target,val+cur,cur,num);
                temp.resize(sz);

                temp+="-" + num.substr(ind,i-ind+1);
                f(i+1,temp,ans,target,val-cur,-cur,num);
                temp.resize(sz);

                temp+="*" + num.substr(ind,i-ind+1);
                f(i+1,temp,ans,target,val-prev+(prev*cur),cur*prev,num);
                temp.resize(sz);
            }

        }

    }
    vector<string> addOperators(string num, int target) {
        string temp = "";

        vector<string> ans;

        f(0,temp,ans,target,0,0,num);
        return ans;
    }
};