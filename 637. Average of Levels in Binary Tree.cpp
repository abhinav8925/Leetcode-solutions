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

 // Problem Link -> 
 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<double> ans;

        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            double sum=0;
            int cnt=0;
            while(sz--){
                TreeNode* ch=q.front();
                q.pop();
                

                if(ch->left){
                    
                    q.push(ch->left);
                    
                }
                if(ch->right){
                    
                    q.push(ch->right);
                    
                }
                sum+=ch->val;
                cnt++;
            }

            
            ans.push_back(sum/cnt);
        }

        return ans;
    }
};
