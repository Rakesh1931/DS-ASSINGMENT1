#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

// Insert at end
void insertEnd(int val) {
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

// Insert before a given value
void insertBefore(int val, int beforeVal) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // If insert before head
    if (head->data == beforeVal) {
        insertBegin(val);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeVal)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value " << beforeVal << " not found!\n";
        return;
    }

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
}

// Insert after a given value
void insertAfter(int val, int afterVal) {
    Node* temp = head;

    while (temp != NULL && temp->data != afterVal)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value " << afterVal << " not found!\n";
        return;
    }

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete specific value
void deleteValue(int val) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // If head contains value
    if (head->data == val) {
        deleteBegin();
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value " << val << " not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search for a value
void searchNode(int val) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }

    cout << "Value " << val << " not found!\n";
}

// Display list
void display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty!\n";
        return;
    }

    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// MAIN MENU
int main() {
    int choice, val, key;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert before a value\n"
             << "4. Insert after a value\n"
             << "5. Delete from beginning\n"
             << "6. Delete from end\n"
             << "7. Delete specific value\n"
             << "8. Search value\n"
             << "9. Display list\n"
             << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                cout << "Insert value: ";
                cin >> val;
                cout << "Before which value? ";
                cin >> key;
                insertBefore(val, key);
                break;

            case 4:
                cout << "Insert value: ";
                cin >> val;
                cout << "After which value? ";
                cin >> key;
                insertAfter(val, key);
                break;

            case 5:
                deleteBegin();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteValue(val);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;

            case 9:
                display();
                break;

            case 10:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
