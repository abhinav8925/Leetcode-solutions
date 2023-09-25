// Problem Link -> https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:


    vector<int> q;
    int f=0,r=0,sz;

    MyCircularQueue(int k) {
        
        q.resize(k);
        f = -1;
        r = f;
        sz = k;
    }
    
    bool enQueue(int x) {
        
        if(isFull())
            return false;
        
        if(isEmpty())
            f = 0;
        
        r = (r+1)%sz;
        q[r] = x;
        return true;
    }
    
    bool deQueue() {
        
        if(isEmpty())
            return false;
        
        if(f == r)
            f = r = -1;
        else
            f = (f+1)%sz;
        
        return 1;

    }
    
    int Front() {
        
        if(isEmpty())
            return -1;
        
        return q[f];
    }
    
    int Rear() {
        if(isEmpty())   
            return -1;
        
        return q[r];

    }
    
    bool isEmpty() {
        
        return f==-1;
    }
    
    bool isFull() {
        
        return ((r+1)%sz) == f;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */