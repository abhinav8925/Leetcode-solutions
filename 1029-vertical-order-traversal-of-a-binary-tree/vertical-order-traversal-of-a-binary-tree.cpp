class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        map<int,vector<pair<int,int>>> temp;
        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){

                auto temp2 = q.front();
                q.pop();

                int cur_row = temp2.second.first;
                int cur_col = temp2.second.second;

                temp[cur_col].push_back({cur_row,temp2.first->val});

                if(temp2.first->left){
                    int new_row = cur_row+1;
                    int new_col = cur_col-1;

                    q.push({temp2.first->left,{new_row,new_col}});
                }

                if(temp2.first->right){
                    int new_row = cur_row+1;
                    int new_col = cur_col+1;

                    q.push({temp2.first->right,{new_row,new_col}});
                }
            }
        }

        for(auto it : temp){
            vector<pair<int,int>> temp3 = it.second;
            sort(temp3.begin(), temp3.end());
            vector<int> column;
            for(auto p : temp3){
                column.push_back(p.second);
            }
            ans.push_back(column);
        }
        return ans;
    }
};