/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
            return nullptr;
        
        Node* n2 = new Node(node->val); 

        unordered_map<Node* , Node*> mp;

        mp[node] = n2;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* ele = q.front();
            q.pop();
            for(Node* next: ele->neighbors){
                if(mp.find(next) == mp.end()){
                Node* temp = new Node(next->val);
                    mp[next] = temp;
                    q.push(next);
                }
                mp[ele]->neighbors.push_back(mp[next]);
            }
            
        }

        return n2;
    }
};