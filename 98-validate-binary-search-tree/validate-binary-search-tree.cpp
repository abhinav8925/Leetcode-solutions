class Solution {
public:
    // bool f(TreeNode* root, long long &prev){
    //     if(root == nullptr)
    //         return true;
        
    //     if(!f(root->left,prev))
    //         return false;
    //     if(root->val<=prev)
    //         return false;
    //     prev = root->val;
    //     if(!f(root->right,prev))
    //         return false;
        
    //     return true;
            
    // }

    bool f(TreeNode* root, long long  mn, long long mx){
        if(!root)
            return true;
        
        if(root->val >= mx || root->val <=mn)
            return false;
        
        return f(root->left,mn,root->val) && f(root->right,root->val,mx);

    }
    bool isValidBST(TreeNode* root) {
        
        if(!root)
            return true;
        long long prev = LLONG_MIN;
        return f(root,LLONG_MIN,LLONG_MAX);
        // return f(root,prev);

    }
};