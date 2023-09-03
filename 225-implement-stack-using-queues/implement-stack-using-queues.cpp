class MyStack {

public:
// queue<int> q1;
// queue<int> q2;
queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            int x=q.front();
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        // int x=q1.front();
        // q1.pop();
        // return x;
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        // int x=q1.front();
        // return x;
        int x=q.front();
        return x;
    }
    
    bool empty() {
        // return q1.empty();
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */