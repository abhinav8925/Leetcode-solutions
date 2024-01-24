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
bool check(vector<int> &cnt){
        int odd_freq=0;
        for(int i=1;i<10;i++) if(cnt[i]%2==1) odd_freq++;
        if(odd_freq>1) return false;
        return true;
    }
    void solve(TreeNode* root, vector<int> cnt,int &ans){
        if(root==NULL)
            return;
        
        cnt[root->val]++;
        if(root->left==NULL && root->right==NULL && check(cnt))
            ans++;
        
        solve(root->left,cnt,ans);
        solve(root->right,cnt,ans);

    }
    int pseudoPalindromicPaths (TreeNode* root) {

     vector<int> cnt(10,0);
     int ans=0;
     solve(root,cnt,ans);
     return ans;   
    }
};