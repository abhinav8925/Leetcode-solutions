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

 // Problem Link -> https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {

            if(!root)
                return 0;
            

            queue<TreeNode*> q;
            
            q.push(root);
            int cnt=0;
            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    TreeNode* ch=q.front();
                    q.pop();
                    if(ch->left){
                        q.push(ch->left);
                    }
                    if(ch->right)
                        q.push(ch->right);
                    
                }
                cnt++;
            }       

            return cnt;
    }
};
