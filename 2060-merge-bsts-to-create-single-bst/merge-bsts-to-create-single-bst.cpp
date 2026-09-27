class Solution {
public:
    bool f(TreeNode* &root, map<int,TreeNode*> &mp, long long mn,long long mx){

        if(root->val >= mx || root->val <= mn)
            return false;
        
        if(root->left && mp.find(root->left->val) != mp.end()){
            int val = root->left->val;
            root->left = mp[val];
            mp.erase(val);
        }
        if(root->right && mp.find(root->right->val) != mp.end()){
            int val = root->right->val;
            root->right = mp[val];
            mp.erase(val);
        }

        if(root->left && !f(root->left,mp,mn,root->val))
            return false;
        
        if(root->right && !f(root->right,mp,root->val,mx))
            return false;
        
        return true;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        map<int,TreeNode*> mp;
        set<int> leaf;

        for(TreeNode* root: trees){
            mp[root->val] = root;
            if(root->left)
                leaf.insert(root->left->val);
            if(root->right)
                leaf.insert(root->right->val);
        }

        TreeNode* root = nullptr;
        for(TreeNode* tree: trees){
            if(leaf.find(tree->val) == leaf.end()){
                root = tree;
                break;
            }
        }

        if(!root)
            return nullptr;
        
        mp.erase(root->val);
        if(!f(root,mp,LLONG_MIN,LLONG_MAX) || !mp.empty())
            return nullptr;
        

        
        return root;
    }
};