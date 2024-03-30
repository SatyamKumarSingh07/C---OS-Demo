#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the middle of the linked list
void insertInMiddle(Node* &head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* slowPtr = head;
        Node* fastPtr = head;
        Node* prev = nullptr;

        // Use a slow pointer and a fast pointer to find the middle
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // Insert the new node after the slow pointer
        if (prev == nullptr) {
            // The list has only one element (even number of elements)
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = slowPtr->next;
            slowPtr->next = newNode;
        }
    }
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
        insertInMiddle(head, i);
    }

    // Traverse and print the linked list
    traverse(head);

    return 0;
}
