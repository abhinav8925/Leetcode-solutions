class Solution {
public:
    TreeNode* f(TreeNode* root, int val){
        if(root == nullptr)
            return new TreeNode (val);
        
        if(root->val > val){
            root->left = f(root->left,val);
        }
        else{
            root->right = f(root->right,val); 
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return f(root, val);
    }
};