class MinStack {
    stack<long long> st; // Use long long to prevent overflow during calculations
    long long mini;

public:
    MinStack() {
        mini = -1; 
    }

    void push(int value) {
        long long val = value; // Cast to long long
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                // Encode the new minimum: 2*val - current_mini
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        // If topVal < mini, it's an encoded value; restore the previous minimum
        if (topVal < mini) {
            mini = 2 * mini - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        // If topVal < mini, the actual value is 'mini'
        if (topVal < mini) {
            return (int)mini;
        }
        return (int)topVal;
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)mini;
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