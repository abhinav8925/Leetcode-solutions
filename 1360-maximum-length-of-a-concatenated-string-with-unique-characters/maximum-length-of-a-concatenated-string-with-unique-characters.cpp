class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans=0;
        f(arr,"",0,ans);
        return ans;   
    }
    void f(vector<string> &arr, string temp,int ind,int &ans){
        if(ans<temp.size())
            ans=temp.size();
        
        for(int i=ind;i<arr.size();i++){
            if(!isval(temp,arr[i]))
                continue;
            
            f(arr,temp+arr[i],i+1,ans);
        }
    }
    bool isval(const string& currentString, const string& newString) {
        unordered_set<char> charSet;

        for (char ch : newString) {
            if (charSet.count(ch) > 0) {
                return false; 
            }

            charSet.insert(ch);

            if (currentString.find(ch) != string::npos) {
                return false;  
            }
        }

        return true;
    }
};