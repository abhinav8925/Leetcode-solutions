
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        bool ans=true;
        int ans2=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    
                    ans=false;
                    break;
                }   
            }
            if(ans==false){
                    ans2=nums1[i];
                    break;
                }
            
        }
        int num=min(nums1[0]*10+nums2[0],nums2[0]*10+nums1[0]);
        
        if(ans)
            return num;
        else 
            return ans2;  
    }
};
