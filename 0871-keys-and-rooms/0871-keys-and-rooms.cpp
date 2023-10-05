// Problem Link -> https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n =rooms.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int ind = q.front();
            q.pop();
            vis[ind]=1;
            for(auto x : rooms[ind]){
                if(!vis[x])
                    q.push(x);
            }

        }
        for(auto v:vis){
            if(!v)
                return 0;
        }
        return 1;
    }
};