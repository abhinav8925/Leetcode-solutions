
class Solution {
public:
    int f(TreeNode* root,bool &fg){
        
        if(root == nullptr)
            return 0;


        int l = f(root->left,fg);
        int r = f(root->right,fg);

        if(abs(l-r) > 1)
            fg=false;
        
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        
        bool fg=true;
        f(root,fg);

        if(!fg)
            return false;
        return true;
    }
};