#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->child = mergeTwoLists(a->child, b);
    } else {
        result = b;
        result->child = mergeTwoLists(a, b->child);
    }
    return result;
}

// Function to flatten the multi-level linked list
Node* flattenLinkedList(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    // Recursively flatten the next linked list
    head->next = flattenLinkedList(head->next);

    // Merge current linked list with the flattened next linked list
    head = mergeTwoLists(head, head->next);

    return head;
}

// Helper function to print the flattened list
void printFlattenedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    // Flatten the linked list
    Node* flattenedList = flattenLinkedList(head);

    // Print the flattened list
    printFlattenedList(flattenedList);

    return 0;
}
