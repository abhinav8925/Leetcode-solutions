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
    int f(TreeNode* root, int ans){
        if(root == nullptr)
            return ans;
        
        int l = f(root->left,ans+1);
        int r = f(root->right,ans+1);
        return max(l,r);
    }
    int maxDepth(TreeNode* root) {
        
        int ans = 0;
        return f(root,ans);
    }
};