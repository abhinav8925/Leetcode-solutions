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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth  == 1){
            TreeNode *ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;

        while(!q.empty()){
            int n = q.size();

            cnt++;
            while(n--){
                TreeNode *cur = q.front();
                q.pop();
                if(cnt!=depth-1){
                    if(cur->left)   q.push(cur->left);
                    if(cur->right)  q.push(cur->right);
                }
                else{
                    TreeNode *ans = new TreeNode(val);
                    ans->left = cur->left;
                    cur->left = ans;
                    TreeNode *ans2 = new TreeNode(val);
                    ans2->right = cur->right;
                    cur->right = ans2;
                }
            }
        }

        return root;
    }
};