class Solution {
public:
    TreeNode* prev=nullptr,*first=nullptr,*second=nullptr;

    void f(TreeNode* &root){
        if(!root)
            return;
        
        f(root->left);
        if(prev && root->val < prev->val){
            if(!first)
                first = prev;
            
            second = root;
        }
        prev = root;
        f(root->right);
    }
    void recoverTree(TreeNode* root) {
       
        if(!root)
            return;
        
        f(root);
        swap(first->val,second->val);

    }
};