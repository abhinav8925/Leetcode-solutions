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

 // Problem Link -> https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:

    int pre(TreeNode* root, int &mx){
        if(root == NULL)
            return 0;
        
        int lh = max(0,pre(root->left,mx));
        int rh = max(0,pre(root->right,mx));

        mx = max(mx,(lh+rh+root->val));

        return root->val + max(lh,rh);

    }

    int maxPathSum(TreeNode* root) {

        int mx = INT_MIN;

        pre(root,mx);

        return mx;
        
    }
};