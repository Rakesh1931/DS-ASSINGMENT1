#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end (helper)
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Reverse Linked List
void reverseList(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;    // store next
        curr->next = prev;    // reverse pointer
        prev = curr;          // move prev
        curr = next;          // move curr
    }
    head = prev;              // new head
}

// Display list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Input: 1 -> 2 -> 3 -> 4 -> NULL
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Original List: ";
    display(head);

    reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
