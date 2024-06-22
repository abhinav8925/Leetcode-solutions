class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int n = nums.size();
        // unordered_map<int,int> m;
        // int res=0,odd=0;

        // m[odd]=1;
        // for(int i=0;i<n;i++){
        //     odd +=(nums[i]%2);

        //     if(m.count(odd-k))
        //         res+=m[odd-k];
            
        //     m[odd]++;
        // }

        // return res;


        int i=0,j=0,prev=0,res=0,n=nums.size(),cnt=0;

        while(j<n){
            if(nums[j]%2){
                cnt++;
                prev=0;
            }

            while(cnt==k){
                prev++;
                if(nums[i]%2)
                    cnt--;
                
                i++;
            }

            res+=prev;
            j++;

        }

        return res;
    }
};