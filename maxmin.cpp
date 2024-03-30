#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
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

// Function to find the maximum element in the linked list
int findMax(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return INT_MIN; // Return minimum integer value to indicate an empty list
    }

    int maxElement = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > maxElement) {
            maxElement = current->data;
        }
        current = current->next;
    }

    return maxElement;
}

// Function to find the minimum element in the linked list
int findMin(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return INT_MAX; // Return maximum integer value to indicate an empty list
    }

    int minElement = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data < minElement) {
            minElement = current->data;
        }
        current = current->next;
    }

    return minElement;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    head = insert(head, 5);
    head = insert(head, 2);
    head = insert(head, 8);
    head = insert(head, 1);
    head = insert(head, 7);

    // Find and print the maximum and minimum elements in the linked list
    int maxElement = findMax(head);
    int minElement = findMin(head);

    cout << "Maximum Element: " << maxElement << endl;
    cout << "Minimum Element: " << minElement << endl;

    return 0;
}
