class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        int i=0,ans=0;
        bool up=false,down=false;

        while(i<n-1){
            
            if(arr[i] < arr[i+1]){
                int start = i;
                while(i<n-1 && arr[i] < arr[i+1]){
                    i++;
                    up=true;
                }
                while(i<n-1 && arr[i]>arr[i+1]){
                    i++;
                    down=true;
                }
                if(up && down)  ans = max(ans,i-start+1);
                up=down=false;
            }
            else
                i++;
        }
        return ans;
    }
};