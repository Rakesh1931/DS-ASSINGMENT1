#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minElement;

public:
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minElement = val;
        } else if (val >= minElement) {
            st.push(val);
        } else {
            st.push(2LL * val - minElement); // encoded value
            minElement = val;
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty.\n";
            return;
        }

        long long top = st.top();
        st.pop();

        if (top < minElement) {
            minElement = 2LL * minElement - top; // decode previous min
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();
        return (top >= minElement) ? top : minElement;
    }

    int getMin() {
        if (st.empty()) return -1;
        return minElement;
    }

    bool isEmpty() {
        return st.empty();
    }
};