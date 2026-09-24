class Solution {
public:
    void flatten(TreeNode* root) {
        stack <TreeNode*> st;

        if(!root)
            return ;

        st.push(root);
        while(!st.empty()){

            TreeNode* temp = st.top();
            st.pop();
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
            
            if(!st.empty())
                temp->right = st.top();
            
            temp->left = nullptr;
        }
    }
};