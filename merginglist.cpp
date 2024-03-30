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

// Function to merge two linked lists into a larger list
Node* mergeLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            mergedList = insert(mergedList, list1->data);
            list1 = list1->next;
        } else {
            mergedList = insert(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // Append remaining nodes from list1 (if any)
    while (list1 != nullptr) {
        mergedList = insert(mergedList, list1->data);
        list1 = list1->next;
    }

    // Append remaining nodes from list2 (if any)
    while (list2 != nullptr) {
        mergedList = insert(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to traverse and print the elements of a linked list
void traverse(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into the first linked list
    for (int i = 1; i <= 5; i++) {
        list1 = insert(list1, i);
    }

    // Insert elements into the second linked list
    for (int i = 6; i <= 10; i++) {
        list2 = insert(list2, i);
    }

    // Merge the two linked lists into a larger list
    Node* mergedList = mergeLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    traverse(mergedList);
    cout << endl;

    return 0;
}
