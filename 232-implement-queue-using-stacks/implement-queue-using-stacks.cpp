class MyQueue {
private:
    stack<int> stk_in, stk_out;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk_in.push(x);
    }
    
    int pop() {
        peek();
        int val = stk_out.top();
        stk_out.pop();
        return val;
    }
    
    int peek() {
        if(stk_out.empty())
        while(!stk_in.empty()){
            stk_out.push(stk_in.top());
            stk_in.pop();
        }
        return stk_out.top();
    }
    
    bool empty() {
        return stk_out.empty() && stk_in.empty();
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