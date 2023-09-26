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

// Problem Link -> https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:

    int pre(TreeNode* root, int &dia){
        if(root == NULL)
            return 0;
        
        int lh = pre(root->left,dia);
        int rh = pre(root->right,dia);

        dia = max(dia,lh+rh);

        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int dia = 0;
        pre(root,dia);
        return dia;
        
    }
};