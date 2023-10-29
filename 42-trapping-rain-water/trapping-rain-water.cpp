class Solution {
public:
    int trap(vector<int>& a) {
        
        int n=a.size();
         vector<int> left(n,0),right(n,0);

        int mx=a[0];
        for(int i=0;i<n;i++){
            if(a[i]<=mx){
                left[i]=mx;
            }
            else{
                left[i]=a[i];
                mx=a[i];
            }
        }
        mx=a[n-1];
        for(int i=n-1;i>=0;i--){
            if(a[i]<=mx){
                right[i]=mx;
            }
            else{
                right[i]=a[i];
                mx=a[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(min(left[i],right[i])-a[i]);
        }

        return ans;

    }
};