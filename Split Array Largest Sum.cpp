// Problem Link -> https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:

    bool checksol(vector<int> &a,int n,int m,int mid){
    

    int cnt=1,ans=0;
    int newsum=0;
    for(int i=0;i<n;i++){
        if(newsum+a[i]<=mid){
            newsum+=a[i];
        }
        else{
            cnt++;
            
            if(cnt>m || a[i]>mid)
                return 0;
            
            newsum=a[i];
        }
        
    }
    return 1;
}
    int splitArray(vector<int>& a, int m) {
        

        // if
        int ans=0,sum=0;
        int n=a.size();
    for(int i =0;i<n;i++){
        sum+=a[i];
    }
    
    int l=1,r=sum;
    int mid=(l+r)/2;
    while(l<=r){
        
        
        if(checksol(a,n, m, mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;

        mid=(l+r)/2;
    }   

    return ans;
    }
};
