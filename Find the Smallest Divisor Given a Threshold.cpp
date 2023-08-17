// Problem Link -> https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/



class Solution {
public:
    
    bool check(vector<int> &a,int n,int mid,int th){

        int sum=0;

        for(int i=0;i<n;i++){
            if(a[i]%mid==0)
                sum+=(a[i]/mid);
            else
                sum+=(a[i]/mid)+1;
            
            
        }

        return sum<=th;


    }
    int smallestDivisor(vector<int>& nums, int th) {


        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());

        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(check(nums,n,mid,th)){
                ans=mid;
                high=mid-1;

            }
            else
                low=mid+1;
        }

        return ans;
    }
};
