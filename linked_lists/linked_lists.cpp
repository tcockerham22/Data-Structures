#include <iostream>
using namespace std;

// Linked list node
class Node {
public:
    int data;
    Node* next;
    Node(int newData) {
        data = newData;
        next = nullptr;
    }
};

// Insert at the beginning
void insertBeg(Node*& head, int newData){
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

// Insert after a given node
void insertAfter(Node* prevNode, int newData){
    if(prevNode == nullptr){
        return;
    }
    Node* newNode = new Node(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Insert at the end
void insertLast(Node*& head, int newData){
    Node* newNode = new Node(newData);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the list
void printList(Node* node){
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

int main(){
    Node* head = nullptr;
    insertLast(head, 6); // 6
    insertBeg(head, 7); // 7 -> 6
    insertBeg(head, 1); // 1 -> 7 -> 6
    insertLast(head, 4); // 1 -> 7 -> 6 -> 4
    insertAfter(head->next, 8); // after 7
    cout << "Linked list:\n";
    printList(head);
    return 0;
}
