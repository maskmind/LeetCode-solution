class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(stk1.size()!=1){
            int popFromstk1=stk1.top();stk1.pop();
            stk2.push(popFromstk1);
        }
        int rt=stk1.top();stk1.pop();
        while(!stk2.empty()){
            int popn=stk2.top();stk2.pop();
            stk1.push(popn);
        }
        return rt;

    }
    
    /** Get the front element. */
    int peek() {
        while(stk1.size()!=1){
            int popFromstk1=stk1.top();stk1.pop();
            stk2.push(popFromstk1);
        }
        int rt=stk1.top();
        while(!stk2.empty()){
            int popn=stk2.top();stk2.pop();
            stk1.push(popn);
        }
        return rt;

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();

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