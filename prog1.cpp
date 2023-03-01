#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL) {
        return false; //empty list cannot be circular
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast != slow) {
        slow = slow->next;
        fast = fast->next;

        if (fast != NULL) {
            fast = fast->next; // pointer moves two nodes at a time
        }
    }

    return (fast == slow); // If fast pointer meets slow pointer, the list is circular
}

int main() {
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    Node* head2 = new Node;
    Node* second2 = new Node;
    Node* third2 = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head; // circular like example 2

    head2->data = 1;
    head2->next = second2;

    second2->data = 2;
    second2->next = third2;

    third2->data = 3;
    third2->next = second2;// circular like example 1

    bool circular = isCircular(head);

    if (circular) {
        cout << "The linked list 1 is circular." << endl;
    } else {
        cout << "The linked list 1 is not circular." << endl;
    }
    bool circular1 = isCircular(head2);

    if (circular1) {
        cout << "The linked list 2 is circular." << endl;
    } else {
        cout << "The linked list 2 is not circular." << endl;
    }

    return 0;
}