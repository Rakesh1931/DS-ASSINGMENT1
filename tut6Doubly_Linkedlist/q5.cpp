#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if list is circular
bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    // Traverse until NULL or head
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    if (temp == head)
        return true;
    else
        return false;
}

int main() {
    // Creating a circular linked list manually
    Node* head = new Node();
    head->data = 10;

    Node* node2 = new Node();
    node2->data = 20;

    Node* node3 = new Node();
    node3->data = 30;

    head->next = node2;
    node2->next = node3;

    // Make it circular
    node3->next = head;  // comment this line to test NON-circular list

    if (isCircular(head))
        cout << "The list is Circular\n";
    else
        cout << "The list is NOT Circular\n";

    return 0;
}
