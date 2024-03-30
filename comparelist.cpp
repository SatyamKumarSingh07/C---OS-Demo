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

// Function to compare two linked lists
bool compareLists(Node* list1, Node* list2) {
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data != list2->data) {
            return false; // Data in nodes is different, lists are not equal
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // If both lists have the same number of nodes and data in each node is the same,
    // they are equal
    return (list1 == nullptr && list2 == nullptr);
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into the first linked list
    for (int i = 1; i <= 5; i++) {
        list1 = insert(list1, i);
    }

    // Insert different elements into the second linked list
    for (int i = 6; i <= 10; i++) {
        list2 = insert(list2, i);
    }

    // Compare the two linked lists
    if (compareLists(list1, list2)) {
        cout << "The two linked lists are equal." << endl;
    } else {
        cout << "The two linked lists are not equal." << endl;
    }

    return 0;
}
