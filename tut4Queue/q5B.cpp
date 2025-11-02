#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) cout << "Empty\n";
        else q.pop();
    }

    int top() { return q.empty() ? -1 : q.front(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << s.top() << endl; // 30
    s.pop();
    cout << s.top() << endl; // 20
}
