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

 // Problem Link -> https://leetcode.com/problems/symmetric-tree/


// Recursive soln

bool ch(TreeNode *l,TreeNode *r){
    if(l==NULL && r==NULL)
        return 1;
    else if(l==NULL || r==NULL)
        return 0;

    

    else if (l->val!=r->val)
        return 0;
    
    return ch(l->left,r->right) && ch(l->right,r->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        

        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();

            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;

        //  Recursive Solution

        // return ch(root->left,root->right);
    }
};
