class Solution {
public:
  
    // TreeNode* f(vector<int> pre, long long mn, long long mx){

    //     if(ind>=pre.size() || pre[ind] > mx)
    //         return nullptr;
        
    //     TreeNode* root = new TreeNode(pre[ind++]);
    //     root->left = f(pre, mn, root->val);
    //     root->right = f(pre,root->val,mx);
    //     return root;
    // }
    TreeNode* f(vector<int> &pre, int &ind, long long bound){

        if(ind>=pre.size() || pre[ind] > bound)
            return nullptr;
        
        TreeNode* root = new TreeNode(pre[ind++]);
        root->left = f(pre, ind, root->val);
        root->right = f(pre,ind,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        // return f(pre,INT_MIN,INT_MAX);
        int i=0;
        return f(pre,i,INT_MAX);
    }
};