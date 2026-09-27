class BTSIterator{
    stack<TreeNode*> st;
    bool rev = true;

    public:
        BTSIterator(TreeNode* root, bool isrev){
            rev = isrev;
            pushAll(root);
        }

        bool hasnext(){
            return !st.empty();
        }
        int next(){
            TreeNode* temp = st.top();
            st.pop();
            if(!rev)
                pushAll(temp->right);
            else
                pushAll(temp->left);
            return temp->val;
        }
        void pushAll(TreeNode* node){
            for(;node!=NULL;){
                st.push(node);
                if(rev)
                    node = node->right;
                else
                    node = node->left;
            }
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        BTSIterator l(root,false);
        BTSIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k)
                return true;
            else if(i+j < k) i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};