class Solution {
public:
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode *root = construct(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* construct(vector<int> &nums,int low,int high){

        if(low>high)
            return nullptr;
        if(low == high)
            return new TreeNode(nums[low]);
        
        int ind = maxi(nums,low,high);
        TreeNode *root = new TreeNode(nums[ind]);
        root->left = construct(nums,low,ind-1);
        root->right = construct(nums, ind + 1, high);


        return root;
    }
    int maxi(vector<int> &nums,int low, int high){
        int mx=INT_MIN;
        int ind = -1;
        for(int i=low;i<=high;i++){
            if(nums[i]>=mx){
                mx=nums[i];
                ind=i;
            }
        }
        return ind;
    }
};