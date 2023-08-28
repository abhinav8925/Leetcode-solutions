// Problem Link -> https://leetcode.com/problems/first-bad-version/submissions/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,h=n;

        if(n==1)
            return 1;

        
        while(l<h){
            int mid=l+(h-l)/2;

            if(isBadVersion(mid)){
                
                h=mid;
            }
            else
                l=mid+1;
        }
        return l;

        // Also Linear Search is a solution but it is giving TLE because of constraints.
        // int i;
        // for(i=1;i<=n;i++){
        //     if(isBadVersion(i))
        //         break;
        // }

        // return i;
    }
};
