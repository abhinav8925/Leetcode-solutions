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

 // Problem Link -> https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
                return 0;
            

            queue<TreeNode*> q;
            
            q.push(root);
            int cnt=0;
            bool ans=true;
            while(!q.empty()){
                int sz=q.size();
                
                while(sz--){
                    TreeNode* ch=q.front();
                    q.pop();
                    if(!ch->left && !ch->right){
                        ans=false;
                        break;
                    }
                    if(ch->left){
                        q.push(ch->left);
                    }
                    if(ch->right)
                        q.push(ch->right);
                    
                }
                cnt++;
                if(!ans)
                    return cnt;
            }       

            return cnt;
        
    }
};
