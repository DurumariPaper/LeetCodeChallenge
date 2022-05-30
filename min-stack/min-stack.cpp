struct Info
{
    int value;
    int minValue;
};

class MinStack {
public:
    stack<Info> st;
    int minValue = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        Info info;
        info.value = val;
        if(st.empty())
            info.minValue = val;
        else
            info.minValue = min(minValue, val);
        
        minValue = info.minValue;
        st.push(info);
        
    }
    
    void pop() 
    {        
        st.pop(); 
        if(st.empty())
        {
            minValue = INT_MAX;
        }
        else
        {
            Info info = st.top();
            minValue = info.minValue;
        }
        
    }
    
    int top() {
        Info info = st.top();
        return info.value;
    }
    
    int getMin() {
        return minValue;
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