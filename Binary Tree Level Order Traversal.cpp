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

 // Problem Link -> https://leetcode.com/problems/binary-tree-level-order-traversal/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;

        if(root==NULL)
            return v;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v1;
            int size=q.size();

            while(size--){
                TreeNode *first=q.front();
                v1.push_back(first->val);

                q.pop();
                if(first->left)
                    q.push(first->left);
                if(first->right)
                    q.push(first->right);
            }
            v.push_back(v1);
        }

        return v;
    }
};
