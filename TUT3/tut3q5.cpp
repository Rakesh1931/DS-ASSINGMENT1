#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;

    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char digit to int
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated result: " << result << endl;

    return 0;
}