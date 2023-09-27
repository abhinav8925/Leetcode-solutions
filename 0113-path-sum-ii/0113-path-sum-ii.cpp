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

    void cntpath(vector<vector<int>> &ans, vector<int> &ds, TreeNode* root, int x) {
    if (root == NULL)
        return;

    
    ds.push_back(root->val);
    if (root->left == NULL && root->right == NULL && x == root->val) {
        ans.push_back(ds);
    }
    

    cntpath(ans, ds, root->left, x - root->val);
    cntpath(ans, ds, root->right, x - root->val);

    ds.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int x) {
    vector<vector<int>> ans;
    vector<int> ds;

    cntpath(ans, ds, root, x);

    return ans;
}

};