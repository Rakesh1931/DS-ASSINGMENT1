#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning / end / after a value
void insert(int val, int posVal = -1, int choice = 1) {
    Node* newNode = new Node{val, NULL};

    // Case 1: List empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // 1 → Insert at beginning
    if (choice == 1) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    // 2 → Insert at end
    if (choice == 2) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        return;
    }

    // 3 → Insert after specific node
    if (choice == 3) {
        Node* temp = head;
        do {
            if (temp->data == posVal) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found!\n";
        delete newNode;
    }
}

// Delete a specific node
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head, *prev = NULL;

    // If head node is to be deleted
    if (head->data == key) {
        while (temp->next != head)
            temp = temp->next;  // find last node

        // Only one node
        if (temp == head) {
            delete head;
            head = NULL;
            return;
        }

        temp->next = head->next;
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Delete node in between or end
    temp = head;
    do {
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Node not found!\n";
}

// Search node
void search(int key) {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            cout << "Node found at position: " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    } while (temp != head);

    cout << "Node not found!\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int ch, val, key;

    while (true) {
        cout << "\n=== Circular Linked List Menu ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Delete a node\n";
        cout << "5. Search a node\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: 
                cout << "Value: "; cin >> val;
                insert(val, -1, 1); break;

            case 2:
                cout << "Value: "; cin >> val;
                insert(val, -1, 2); break;

            case 3:
                cout << "Value: "; cin >> val;
                cout << "After which value? ";
                cin >> key;
                insert(val, key, 3); break;

            case 4:
                cout << "Delete value: ";
                cin >> key;
                deleteNode(key); break;

            case 5:
                cout << "Search value: ";
                cin >> key;
                search(key); break;

            case 6:
                display(); break;

            case 7:
                return 0;
        }
    }
}
