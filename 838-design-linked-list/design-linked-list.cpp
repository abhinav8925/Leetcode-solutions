// Problem Link -> https://leetcode.com/problems/design-linked-list/



struct Node {
    int data;
    Node* next;
};

class MyLinkedList {
    Node* head;     
    int length;     

public:
    MyLinkedList() : head(nullptr), length(0) {}

   
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1; 
        }

        Node* t = getNode(index);   
        return t->data;             
    }

    
    void addAtHead(int val) {
        Node* newNode = createNode(val);    
        newNode->next = head;               
        head = newNode;                     
        length++;                           
    }

    
    void addAtTail(int val) {
        Node* newNode = createNode(val);   

        if (head == nullptr) {
            head = newNode;                 
        } else {
            Node* t = getNode(length - 1);  
            t->next = newNode;              
        }
        length++;                           
    }

    
    void addAtIndex(int index, int val) {
        if (index > length) {
            return;                         
        } else if (index <= 0) {
            addAtHead(val);                 
        } else if (index == length) {
            addAtTail(val);                
        } else {
            Node* t = getNode(index - 1);   
            Node* newNode = createNode(val);
            newNode->next = t->next;        
            t->next = newNode;              
            length++;                       
        }
    }

    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;                         
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;              
            deleteNode(temp);               
        } else {
            Node* t = getNode(index - 1);   
            Node* temp = t->next;            
            t->next = t->next->next;        
            deleteNode(temp);               
        }
        length--;                           
    }

    
    int len() {
        return length;
    }

private:
    
    Node* getNode(int index) {
        Node* t = head;
        for (int i = 0; i < index; i++) {
            t = t->next;
        }
        return t;
    }

    
    Node* createNode(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        return newNode;
    }

    
    void deleteNode(Node* node) {
        delete node;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */