class MinStack {
public:
    stack<int>st;
    stack<int>ex;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(ex.empty())ex.push(val);
        else if(ex.top()<val)ex.push(ex.top());
        else ex.push(val);
    }
    
    void pop() {
        st.pop();
        ex.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ex.top();
    }
};
