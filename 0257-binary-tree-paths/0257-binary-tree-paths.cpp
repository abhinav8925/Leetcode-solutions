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

 // Problem Link -> https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:

    void abc(vector<string>& ans,string s,TreeNode* root){
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }
        if(root->left){
            abc(ans,s+"->",root->left);
        }
        if(root->right){
            
            abc(ans,s+"->",root->right);
        }
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        abc(ans,s,root);
        return ans;
    }
};