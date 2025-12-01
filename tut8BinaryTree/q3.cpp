#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ============================
// INSERT (No duplicates)
// ============================
Node* insertNode(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    else 
        cout << "Duplicate Key Not Allowed: " << key << endl;

    return root;
}

// ============================
// FIND MINIMUM NODE
// ============================
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// ============================
// DELETE NODE
// ============================
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ============================
// MAX DEPTH OF BST
// ============================
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// ============================
// MIN DEPTH OF BST
// ============================
int minDepth(Node* root) {
    if (root == NULL) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left == 0) return 1 + right;
    if (right == 0) return 1 + left;

    return 1 + min(left, right);
}

// ============================
// INORDER PRINT (for checking)
// ============================
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ============================
// MAIN FUNCTION
// ============================
int main() {
    Node* root = NULL;

    // Insert elements
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Delete a node
    cout << "Deleting 20...\n";
    root = deleteNode(root, 20);

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    cout << "Maximum depth of BST = " << maxDepth(root) << endl;
    cout << "Minimum d
