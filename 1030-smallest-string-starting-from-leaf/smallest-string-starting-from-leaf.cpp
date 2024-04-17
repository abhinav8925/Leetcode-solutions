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
    string ans = "|",s;
    void change(TreeNode* root){
        if(root==NULL){
            return;
        }
        char cur = 'a'+ root->val;
        s+=cur;
        if(root->left==NULL && root->right==NULL){
            string t = s;
            reverse(t.begin(),t.end());
            ans = min(ans,t);
        }
        
        change(root->left);
        change(root->right);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        
        
        change(root);
        return ans;
    }
};