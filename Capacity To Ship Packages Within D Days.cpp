// Problem Link -> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:


    bool check(vector<int> &wt,int mid,int d,int n){
        int sum=0,cnt=1;

        for(int i=0;i<n;i++){
            if(sum+wt[i] <=mid){
                sum+=wt[i];
            }
            
            else{
                sum=wt[i];
                cnt++;
            }
        }

        return cnt<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int n=weights.size();

        int sum=0;
        for(int i=0;i<n;i++)
            sum+=weights[i];

        int l=*max_element(weights.begin(),weights.end()),h=sum;

        int ans=-1;

        while(l<=h){
            int mid=(l+h)/2;

            if( check(weights,mid,days,n)){
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }

        return ans;
        
    }
};
