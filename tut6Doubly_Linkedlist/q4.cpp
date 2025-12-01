#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert character at end
void insertEnd(char ch) {
    Node* newNode = new Node();
    newNode->data = ch;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (head == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    // Move right pointer to last node
    while (right->next != NULL)
        right = right->next;

    // Compare from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string s = "radar";  // example

    for (int i = 0; i < s.length(); i++)
        insertEnd(s[i]);

    if (isPalindrome())
        cout << "The Doubly Linked List is a Palindrome\n";
    else
        cout << "The Doubly Linked List is NOT a Palindrome\n";

    return 0;
}
