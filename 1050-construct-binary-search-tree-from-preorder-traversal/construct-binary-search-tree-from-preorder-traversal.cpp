class Solution {
public:
    int ind=0;
    TreeNode* f(vector<int> pre, long long mn, long long mx){

        if(ind>=pre.size() || pre[ind] > mx)
            return nullptr;
        
        TreeNode* root = new TreeNode(pre[ind++]);
        root->left = f(pre, mn, root->val);
        root->right = f(pre,root->val,mx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return f(pre,INT_MIN,INT_MAX);
    }
};