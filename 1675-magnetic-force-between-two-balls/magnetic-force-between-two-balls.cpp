class Solution {
public:
    bool ispos(int mid,vector<int> pos, int m){
        int prev = pos[0];
        int cnt=1;
        for(int i=1;i<pos.size();i++){
            int cur =pos[i];
            if(cur-prev >=mid)
                cnt++,prev=cur;
            
            if(cnt==m)
                break;
        }

        return cnt==m;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(begin(pos),end(pos));
        int low=1,high=pos[pos.size()-1]-pos[0],ans=0;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(ispos(mid,pos,m)){
                ans = mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};