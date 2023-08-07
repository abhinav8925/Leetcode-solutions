// Problem Link -> https://leetcode.com/problems/4sum/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {

        vector<vector<int>> ans;

        int n=a.size();
        sort(a.begin(),a.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && a[i]==a[i-1])
                continue;
            for(int j=i+1;j<n-1;j++){
                    if(j>i+1 && a[j]==a[j-1])
                        continue;

                    int l=j+1;
                    int r=n-1;

                    while(l<r){
                        long long sum=a[i];
                        sum+=a[j];
                        sum+=a[l];
                        sum+=a[r];
                        if(sum==target){
                            vector<int> temp={a[i],a[j],a[l],a[r]};
                            ans.push_back(temp);
                            l++;
                            r--;

                            while(l<r && a[l]==a[l-1])  l++;
                            while(l<r && a[r]==a[r+1])  r--;
                        }
                        else if(sum<target)
                            l++;
                        else
                            r--;
                    }
                
            }
        }

        return ans;
        
    }
};
