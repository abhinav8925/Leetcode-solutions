/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root){
        
        if(root==NULL)
            return NULL;
        
        int l=solve(root->left);
        int r=solve(root->right);

        int check = root->val;
        if(root->val == 2)
            root->val=l || r;
        else if(root->val == 3)
            root->val=l && r;
        
        return root->val;

    }

    bool evaluateTree(TreeNode* root) {
        
    
        return solve(root);
    }
};