// Problem Link -> https://leetcode.com/problems/kth-missing-positive-number/


class Solution {
public:


    int findKthPositive(vector<int>& arr, int k) {

    // Brute Force 
    /*
    int mx=arr[arr.size()-1];
    vector<int> p(mx);
    int j=0;
    for(int i=0;i<mx;i++)
    {
        int o=i+1;
        if(o==arr[j])
            j++;
        else if(o!=arr[j])
            p[i]=o;
            
    }
    //
    int k=K;
        for(int i=0;i<n-1;i++){
            if(a[i]<=k)
                k++;
            else
                break;
        }
    //
    
    vector<int> v;
    for(int i=0;i<p.size();i++)
        if(p[i]!=0)
            v.push_back(p[i]);
    
    int m=v[k-1];
    return m;
    */

    // Optimal 
    // find the point where the element should be present and apply BS there

    int l=0,h=arr.size()-1;

    while(l<=h){

        int mid=(l+h)/2;

        int mis=arr[mid]-(mid+1);

        if(mis < k)
            l=mid+1;
        else
            h=mid-1;
    }

    return h+1+k; // l+k;

 
    }
};
