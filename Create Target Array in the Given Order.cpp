// Problem Link -> https://leetcode.com/problems/create-target-array-in-the-given-order/


class Solution {
public:
    void move(vector<int> &v, int n,int pos){

         for(int i=n-1;i>pos;i--){
             v[i]=v[i-1];
         }
    }
     
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> v(n,-1); 
        for(int i=0;i<n;i++){
            if(v[index[i]]==-1){
                v[index[i]]=nums[i];
            }
            else{
                move(v,n,index[i]);
                v[index[i]]=nums[i];
            }
        }
    

        return v;
    }
};

