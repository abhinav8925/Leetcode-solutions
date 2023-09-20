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

 // Problem Link -> https://leetcode.com/problems/kth-smallest-element-in-a-bst/


class Solution {
public:
    int ans,cnt=0;

    void in(TreeNode *root, int &k){
        if(root==NULL)
            return ;
        in(root->left,k);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        in(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        

        in(root,k);

        return ans;
    }
};