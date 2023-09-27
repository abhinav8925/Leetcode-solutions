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

 // Problem Link -> https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    void _rightSideView(TreeNode* curr, vector<int>& soln, unordered_map<int, int>& marked, int height) {
        if(!curr) return;
        if(!marked[height]) {
            marked[height] = 1;
            soln.push_back(curr->val);
        }
        _rightSideView(curr->right, soln, marked, height+1); 
        _rightSideView(curr->left, soln, marked, height+1); 
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> soln;
        unordered_map<int, int> marked;
        _rightSideView(root, soln, marked, 1);
        return soln;
    }
};