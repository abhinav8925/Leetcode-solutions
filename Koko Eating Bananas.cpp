// Problem Link -> https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:

    bool check(vector<int> &v,int h,int mid){

            long long  cnt=0;
            int n=v.size();
            for(int i=0;i<n;i++){
                if(v[i]%mid==0){
                    cnt+=(v[i]/mid);
                }
                else{
                    cnt+=(v[i]/mid)+1;
                }

                if(cnt>h)   
                    return 0;
            }
            return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        

        int ans=-1;
        int n=piles.size();
        int l=1,hh=INT_MAX;
        while(l<=hh){
            int mid=l+(hh-l)/2;

            if(check(piles,h,mid)){
                ans=mid;
                hh=mid-1;
            }
            else
                l=mid+1;
        }

        return ans;
    }
};
