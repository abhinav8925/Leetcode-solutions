class Solution {
public:
    TreeNode* f(TreeNode* root, int val){
        if(!root)
            return nullptr;
        
        if(root->val == val)
            return root;
        if(root->val > val){
            return f(root->left,val);
        }else
            return f(root->right,val);

        // retur÷n nullptr;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root,val);
    }
};