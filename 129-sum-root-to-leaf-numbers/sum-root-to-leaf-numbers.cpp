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
    // int sum=0;
    
    int pre(TreeNode* root, int temp){
        if(root == NULL)
            return 0;
        
        temp = temp*10 + root->val;

        if(root->left==NULL && root->right==NULL){
            return temp;
        }
        return pre(root->left,temp) +  pre(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        
        return pre(root,0);
    }
};