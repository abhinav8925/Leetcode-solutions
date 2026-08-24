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
    int dfs(TreeNode* root,int &cnt){
        if(root == nullptr)
            return 0;
        
        int l = 1 + dfs(root->left,cnt);
        int r = 1 + dfs(root->right,cnt);

        cnt = max(l,r);
        return cnt;
    }
    int maxDepth(TreeNode* root) {
        int val=0;
        int cnt = dfs(root,val);
        return cnt;
    }
};