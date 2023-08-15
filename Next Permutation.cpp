// Problem Link -> https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // Brute Force -> generate all permuatation and then perform a linear search for the given permutaion and print the next one


        // better -> to use STL library which will automatically genrate the next permutation of the given array
        
        // optimal -> find the breakpoint and then swap the element(next greater or equal) with the breakpoint element and then reverse the array after the breakpoint



        int ind=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }

        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[ind],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());


        return;

    }
};
