class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(p->val < root->val && q->val < root->val)
            return f(root->left,p,q);
        if(p->val >root->val && q->val > root->val)
            return f(root->right,p,q);
        
        return root;
        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return f(root,p,q);
    }
};