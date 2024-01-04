class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();

        for(int i=0;i<n;i++)
            m[nums[i]]++;

        int cnt=0;
        for(auto it:m){
            
            int k = it.second;
            if(k==1)
                return -1;
            else if(k%3==0)
                cnt+=k/3;
            else if(k%3==1)
                cnt+=(k-1)/3+1;
            else
                cnt+=k/3+1;
        }

        return cnt;
    }
};