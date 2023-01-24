class MyCircularQueue {
public:
    vector<int> q;
    int size;
    int rear, front;
    MyCircularQueue(int k) {
        size = k;
        q.resize(k, -1); //vector is initially filled with -1.....
        rear = -1;
        front = -1;   
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(rear == -1 && front == -1){
            rear = 0;
            front = 0;
        }
        else
            rear = (rear+1)%size;

        q[rear] = value;
        return true;    
        
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;

        q[front] = -1;
        front = (front+1)%size;
        if(front == (rear + 1) % size) {
            front = -1;
            rear = -1;
        }
        return true;    
        
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
        
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
        
    }
    
    bool isEmpty() {
        if(rear == -1 && front == -1)
            return true;
        return false;        
    }
    
    bool isFull() {
        if(front == (rear+1)%size)
            return true;
        return false;    
        
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
