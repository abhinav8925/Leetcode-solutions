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
    int sumOfLeftLeaves(TreeNode* root) {
        

        if(root==NULL )//|| (!root->left &&  !root->right))
            return 0;
        
     
    

        int ans=0;
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()){

            int sz=q.size();
            
            while(sz--){

                auto it=q.front();

                q.pop();
                TreeNode *isp=it.first;
                int fg=it.second;

                if(fg==1 && !isp->left && !isp->right)
                    ans+=isp->val;
                
                if(isp->left)
                    q.push({isp->left,1});
                if(isp->right)
                    q.push({isp->right,2});
                
            }
        } 

        return ans;

    }
};