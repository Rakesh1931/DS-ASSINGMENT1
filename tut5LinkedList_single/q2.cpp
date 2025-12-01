#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
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

// Count occurrences of key
int countKey(Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

// Delete all occurrences of key
void deleteAllOccurrences(Node*& head, int key) {
    // Delete from beginning if needed
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL) return;

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example list: 1->2->1->2->1->3->1
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 1);

    int key = 1;

    cout << "Original List: ";
    display(head);

    int count = countKey(head, key);
    cout << "Occurrences of " << key << " = " << count << endl;

    deleteAllOccurrences(head, key);

    cout << "List after deleting all occurrences of " << key << ": ";
    display(head);

    return 0;
}
