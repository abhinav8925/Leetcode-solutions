// Problem Link -> https://leetcode.com/problems/design-browser-history/

struct Node{
    Node *prev = nullptr;
    Node *next = nullptr;

    const string url;
    Node(const string &url):url(url){ }
};

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        
        cur = new Node(homepage);
    }
    
    void visit(string url) {
        
        cur->next = new Node (url);
        cur->next->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {

        while(cur->prev && steps--){
            cur=cur->prev;
        }
        return cur->url;
        
    }
    
    string forward(int steps) {
        while(cur->next && steps--){
            cur = cur->next;
        }
        return cur->url;
        
    }
    private:
        Node *cur = nullptr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */