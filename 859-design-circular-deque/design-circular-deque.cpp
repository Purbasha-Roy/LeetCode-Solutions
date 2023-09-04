class MyCircularDeque {
public:
deque<int> dq;
int count;
int size;
    MyCircularDeque(int k) {
        count=0;
        size=k;
    }
    
    bool insertFront(int value) {
        if(count<size){
            dq.push_front(value);
            count++;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(count<size){
            dq.push_back(value);
            count++;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        dq.pop_front();
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        dq.pop_back();
        count--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dq.front();
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() {
        if(count==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==count){
            return true;
        }
        return false;
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