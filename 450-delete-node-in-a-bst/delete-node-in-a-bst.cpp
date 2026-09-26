class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        
        TreeNode* par = nullptr;
        TreeNode* cur = root;

        while(cur && cur->val!=key){
            par = cur;
            if(cur->val > key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if(!cur)
            return root;
        
        TreeNode* temp;
        if(!cur->left)
            temp = cur->right;
        else if(!cur->right)
            temp = cur->left;
        else{
            temp = cur->right;
            TreeNode* temp2 = temp;
            while(temp2->left)
                temp2 = temp2->left;
            
            temp2->left = cur->left;
        }
        if(!par)
            return temp;
        if(par->left == cur)
            par->left = temp;
        else
            par->right = temp;
        
        return root;
    }
};