class MyQueue {
public:
// stack<int> s1;
// stack<int> s2;
stack<int> in;
stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        // while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        // s1.push(x);
        // while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }
        in.push(x);
    }
    
    int pop() {
        // int x=s1.top();
        // s1.pop();
        // return x;
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int ans=out.top();
        out.pop();
        return ans;
    }
    
    int peek() {
        // int x=s1.top();
        // return x;
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        // return s1.empty();
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */