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

 // Problem Link -> https://leetcode.com/problems/find-bottom-left-tree-value/


  
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;

        queue<TreeNode*> q;
        q.push(root);
        

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                TreeNode *ch = q.front();
                q.pop();

                if(ch->left)
                    q.push(ch->left);
                if(ch->right)
                    q.push(ch->right);
            }
            if(!q.empty())
                ans.push_back(q.front()->val);
        }

        return ans[ans.size()-1];
    }
};