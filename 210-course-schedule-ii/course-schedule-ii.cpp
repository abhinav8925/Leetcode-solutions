class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {

        vector<vector<int>> adj(num);
        vector<int> ind(num,0);
        for(int i=0;i<pre.size();i++){
            int a = pre[i][0];
            int b = pre[i][1];
            adj[b].push_back(a);
            ind[a]++;
        }
        
        queue<int> q;

        for(int i=0;i<num;i++){
            if(ind[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                int nbr = adj[node][i];
                ind[nbr]--;
                if(ind[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(ans.size() == num)
            return ans ;
        return  {};

        
    }
};