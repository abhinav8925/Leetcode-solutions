// Problem Link -> https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            int find=max(nums1[i],nums2[j]);
            if(nums1[i]==find && nums2[j]==find){
                v.push_back(find);

                while(i<n1 && nums1[i]==find)i++;
                while(j<n2 && nums2[j]==find)j++;
            }
            else{
                if(nums1[i]<find)
                    i++;
                else if(nums2[j]<find)
                    j++;
            }
        }
        return v;
    }
};
