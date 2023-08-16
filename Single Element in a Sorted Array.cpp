// Problem Link -> https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {


        int n=a.size();
            int l=0,h=n-2;
            int ans=-1;
            
            if (n == 1) return a[0];
    if (a[0] != a[1]) return a[0];
    if (a[n - 1] != a[n - 2]) return a[n - 1];
            
            while(l<=h){
                int mid=(l+h)/2;

                if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1]){
                    ans=a[mid];
                    break;
                }
                
                else if((mid%2==1 && a[mid]==a[mid-1]) ||  (mid%2==0 &&a[mid]==a[mid+1]))
                    l=mid+1;
                else
                    h=mid-1;

            }

            return ans;
    }
};
