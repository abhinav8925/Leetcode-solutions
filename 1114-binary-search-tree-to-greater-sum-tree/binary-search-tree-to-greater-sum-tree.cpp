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
    void rev_in_order(TreeNode* root, int &ans){
        if(root==NULL)
            return ;
        
        rev_in_order(root->right,ans);
        ans+=root->val;
        root->val=ans;
        rev_in_order(root->left,ans);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;

        rev_in_order(root,sum);
        return root;
    }
};