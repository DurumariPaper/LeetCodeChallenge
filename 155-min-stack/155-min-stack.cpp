class MinStack {
public:
    stack<int> st;
        map<int,int> data;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        data[val]++;
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        data[top]--;
        if(data[top] == 0)
            data.erase(top);
    }
    
    int top() {
        return st.top();    
    }
    
    int getMin() {
        return data.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */