class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();

        int i=0,j=0;
        while(j<n){
            if(arr[j]==0)
                j++;
            else{
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
        }
    }
};