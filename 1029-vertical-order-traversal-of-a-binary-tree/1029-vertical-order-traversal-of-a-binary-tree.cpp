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

// Problem Link -> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int,multiset<int>>> node;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto  p = q.front();
            q.pop();

            TreeNode *ch = p.first;

            int x = p.second.first;
            int y = p.second.second;

            node[x][y].insert(ch->val);

            if(ch->left)
                q.push({ch->left, { x-1,y+1}});
            if(ch->right)
                q.push({ch->right,{x+1,y+1}});
        }

        vector<vector<int>> ans;

        for(auto p: node){
            vector<int> temp;
            for(auto o:p.second){
                temp.insert(temp.end(),o.second.begin(),o.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};