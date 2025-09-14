#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (top < MAX - 1) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0'; // Return null character if stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    Stack s;
    int len = strlen(str);

    // Push all characters onto the stack
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    // Pop characters to reverse the string
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << endl;
    return 0;
}