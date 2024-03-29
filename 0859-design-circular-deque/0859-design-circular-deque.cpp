// Problem Link -> https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
public:

    vector<int> v;
    int front = -1;
    int rear = -1;
    int sz = 0;
    MyCircularDeque(int k) {
        v.resize(k,-1);
        sz = k;
    }
    
    bool insertFront(int value) {
        
        if(isFull())
            return 0;
        else if(front==-1){
            front = 0;
            rear = 0;
        }
        else if(front == 0 && rear != sz-1){
            front   = sz-1;
        }
        else{
            front--;
        }
        v[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        
        if(isFull())
            return false;
        
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear  == sz-1 && front != -1)
            rear = 0;
        
        else
            rear++;
        
        v[rear] = value;
        return true;
    }
    
     bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }

        int ans=v[front];
        v[front]=-1;

        
        if(front==rear){
            front=-1;
            rear=-1;
        }

        
        else if(front==sz-1){
            front=0;
        }

        
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
       
        if(isEmpty()){
            return false;
        }

        int ans=v[rear];
        v[rear]=-1;

        
        if(front==rear){
            front=-1;
            rear=-1;
        }

        
        else if(rear==0){
            rear=sz-1;
        }

        
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        
        if(isEmpty()){
            return -1;
        }
        else{
            return v[front];
        }
    }
    
    int getRear() {
        
        if(isEmpty()){
            return -1;
        }
        else{
            return v[rear];
        }
    }
    
    bool isEmpty() {
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if( (front==0 && rear==sz-1) || ( front!=0 && rear==(front-1)%(sz-1)) ){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */