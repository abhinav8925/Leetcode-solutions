// Problem Link -> https://leetcode.com/problems/string-compression/


// Brute  Force 
// class Solution {
// public:
//     int compress(vector<char>& s) {
        
//         int cnt=0, n=s.size();
//         string ans="";
//         for(int i=0;i<n;i++){
//             if(i+1<n && s[i]==s[i+1]){
//                     cnt++;
//                 }
//             else{
//                 ans+=s[i];
//                 if(cnt>=1)
//                     ans+=to_string(cnt+1);
                
//                 cnt=0;
//             }
//         }
//         for(int i=0;i<ans.size();i++){
//             s[i]=ans[i];
//         }
//         return ans.size();
//     }
// };


// Optimal

class Solution {
public:
    int compress(vector<char>& s) {
        int i=0,ind=0;
        int n=s.size();
        while(i<n){
            int j=i+1;
            while(j<n && s[i]==s[j])
                j++;
            
            s[ind]=s[i];
            ind++;
            
            int cnt=j-i;
            if(cnt>1){
                string freq=to_string(cnt);
                for(char ch:freq){
                    s[ind++]=ch;
                }
            }

            i=j;
        }
        return ind;
    }
};
