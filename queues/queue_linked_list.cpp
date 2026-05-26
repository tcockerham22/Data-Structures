#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {} // Constructor using initializer list
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}
    // Destructor to free up memory
    ~Queue() {
        while (front != nullptr) {
            deQueue();
        }
    }

    // Enqueue operation
    void enQueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;

    }

    // Dequeue operation
    void deQueue() {
        if(front == nullptr){
            return;
        }
        Node* temp = front;
        front = front->next;

        if(front == nullptr){
            rear = nullptr;
        }

        delete temp;
    }

    // Utility function to print the queue
    void printQueue() const {
        Node* temp = front;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout<< "\n";
    }

    // Get the front element
    int getFront() const {
        if(front == nullptr){
            throw runtime_error("Empty queue");
        }
        return front->data;
    }

    // Get the rear element
    int getRear() const {
        if(rear == nullptr){
            throw runtime_error("Empty queue");
        }
        return rear->data;
    }
};


int main() {
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    q.printQueue();
    try {
        cout << "Queue Front : " << q.getFront() << endl;
        cout << "Queue Rear : " << q.getRear() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
