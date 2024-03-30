#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
Node* insert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

// Function to delete a node with a given value from the linked list
Node* deleteNode(Node* head, int key) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return head;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Element " << key << " not found in the linked list." << endl;
    } else {
        prev->next = current->next;
        delete current;
        cout << "Element " << key << " deleted from the linked list." << endl;
    }

    return head;
}

// Function to traverse and print the elements of the linked list
void traverse(Node* head) {
    Node* current = head;
    cout << "Linked List Elements: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    for (int i = 1; i <= 5; i++) {
        head = insert(head, i);
    }

    // Print the original linked list
    traverse(head);

    // Delete a node with a given value (e.g., 3)
    int keyToDelete = 3;
    head = deleteNode(head, keyToDelete);

    // Print the modified linked list
    traverse(head);

    return 0;
}
