
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std:: unordered_map<Node*, Node*> mp;
        Node* cur = head;

        while(cur){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur){
            Node* copy = mp[cur];
            copy->next = mp[cur->next];
            copy->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};