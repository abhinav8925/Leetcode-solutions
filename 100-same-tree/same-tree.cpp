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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        
         if(r1 == NULL && r2 == NULL) return true;
        if(r1 != NULL && r2 == NULL) return false;
        if(r1 == NULL && r2 != NULL) return false;
        
        int data1 = r1->val;
        int data2 = r2->val;
        
       bool lp = isSameTree(r1->left,r2->left);
        bool rp = isSameTree(r1->right,r2->right);
        
        if(lp && rp && data1 == data2){
            return true;
        }else
            return false;
    }
};