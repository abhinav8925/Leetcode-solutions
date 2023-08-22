// Problem Link -> https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n=a.size();


        string k="";

        vector<string> s;
        
        for(int i=0;i<n;i++){
            int j=i;
            while(j+1<n && a[j+1]==a[j]+1)
                j++;
            
            if(j>i){
                k+=to_string(a[i]);
                k+="->";
                k+=to_string(a[j]);
            }
            else{
                k+=to_string(a[i]);
            }
            s.push_back(k);
            k="";
            i=j;
        }

        return s;
    }
};
