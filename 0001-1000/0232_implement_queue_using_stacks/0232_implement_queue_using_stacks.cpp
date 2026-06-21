class MyQueue {
    stack<int> s1, s2;
    int top;
public:
    MyQueue() {
        top = -1;
    }
    
    void push(int x) {
        if(s1.empty()){
            top = x;
        }
        s1.push(x);
    }
    
    int pop() {
        int element = top;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        if(!s2.empty()){
            top = s2.top();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return element;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return s1.empty();
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