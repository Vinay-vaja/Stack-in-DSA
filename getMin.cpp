#include <iostream>
#include <stack>
using namespace std;

class Stack {
public:
    stack<int> st;
    int mini;

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2 * val - mini); // store encoded value
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        int topVal = st.top();
        st.pop();

        if (topVal < mini) {
            mini = 2 * mini - topVal; // decode previous min
        }
    }

    int top() {
        if (st.empty()) return -1;
        int x = st.top();
        if (x < mini) return mini; // it was encoded
        return x;
    }

    int getMin() {
        return st.empty() ? -1 : mini;
    }
};

int main() {
    Stack s;
    s.push(15);
    s.push(12);
    s.push(8);
    s.push(20);
    s.push(-1);

    s.pop();
    cout << "Top: " << s.top() << endl;      // 20
    cout << "Min: " << s.getMin() << endl;   // 8

    s.pop();
    cout << "Top: " << s.top() << endl;      // 8
    cout << "Min: " << s.getMin() << endl;   // 8

    return 0;
}
