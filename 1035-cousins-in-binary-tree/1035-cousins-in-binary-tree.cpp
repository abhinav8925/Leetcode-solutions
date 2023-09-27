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

 // Problem Link -> https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        

        queue<TreeNode*> q;
        

        
        TreeNode* xp = NULL,*yp=NULL;
        
        q.push(root);

        while(!q.empty()){

            int sz = q.size();
            while(sz--){
                TreeNode *ch = q.front();

                q.pop();

                

                if(ch->left){
                    if(ch->left->val == x){
                        xp = ch;
                    }
                    if(ch->left->val == y){
                        yp = ch;
                    }
                    q.push(ch->left);
                }
                    
                if(ch->right){
                    if(ch->right->val == x){
                    xp = ch;
                    }
                    if(ch->right->val == y){
                        yp = ch;
                    }
                    q.push(ch->right);
                }
                    
            }

            if(xp!=NULL && yp!=NULL){
                if(xp != yp)
                    return 1;
            }

            xp=NULL;
            yp=NULL;
            

        }

        return 0;
    }
};