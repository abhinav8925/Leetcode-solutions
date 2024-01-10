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
    unordered_map<int,vector<int>> adj;
    void constgraph(TreeNode *root){

        if(root == NULL)
            return;
        
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);

        }
        if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        constgraph(root->left);
        constgraph(root->right);

    }
    int amountOfTime(TreeNode* root, int start) {
        
        constgraph(root);
        queue<int> q;

        q.push(start);
        int min=-1;

        unordered_set<int> vis;

        while(!q.empty()){
            int sz = q.size();
            min++;
            while(sz--){
                int k = q.front();
                q.pop();
                vis.insert(k);
                
                for(auto it:adj[k]){
                    if(vis.find(it)==vis.end()){
                        q.push(it);

                    }
                }
            }
        }

        return min;
    }
};