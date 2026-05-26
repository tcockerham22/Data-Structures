#include <iostream>
using namespace std;

// A doubly linked list node
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int newData) {
        data = newData;
        next = nullptr;
        prev = nullptr;
    }
};

// Insert at the beginning
void insertBeg(Node*& head, int newData){
    Node* newNode = new Node(newData);
    newNode->next = head;
    if(head != nullptr){
        head->prev = newNode;
    }
    head = newNode;
}

// Insert after a given node
void insertAfter(Node* prevNode, int newData){
    if(prevNode == nullptr){
        return;
    }
    Node* newNode = new Node(newData);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }
}

// Insert at the end
void insertAtEnd(Node*& head, int newData){
    Node* newNode = new Node(newData);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}

// Print forward and backward
void printList(Node* node)
{
    Node* last = nullptr;
    cout << "\nForward: ";
    while (node != nullptr) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << "\nReverse: ";
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << "\n";
}

int main()
{
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertBeg(head, 20);
    insertBeg(head, 40);
    insertAtEnd(head, 40);
    insertAfter(head->next, 8);
    cout << "DLL is:";
    printList(head);
    return 0;
}
