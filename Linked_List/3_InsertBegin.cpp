#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};



Node* insertAtBegin(Node *head, int x) {
    Node* temp = new Node(x);
    temp -> next = head;
    return temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    head = insertAtBegin(head, 1);
    head = insertAtBegin(head, 2);
    head = insertAtBegin(head, 3);
    head = insertAtBegin(head, 4);
    head = insertAtBegin(head, 5);
    cout << "Linked List: ";
    printList(head);
    return 0;
}
