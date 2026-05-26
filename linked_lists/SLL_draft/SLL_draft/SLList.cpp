#include "SLList.h"
#include <iostream>

template<typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template<typename T>
unsigned SLList<T>::size() const {
    return listSize;
}

template<typename T>
bool SLList<T>::empty() const {
    return (listSize == 0);
}

template<typename T>
void SLList<T>::push_front(const T& value) {
    head = new SLLNode<T>(value, head);

    listSize++;

    if(size() == 1){
        tail = head;
    }

}

template<typename T>
void SLList<T>::print() const {
    SLLNode<T>* cur = head;

    while(cur != NULL){
        std::cout << cur->data << " -> ";
        cur = cur->next;
   }
   std::cout << "\n";
}

template<typename T>
void SLList<T>::push_back(const T& value) {
    if(empty()){
        push_front(value);
    }
    else{
        tail->next = new SLLNode<T>(value);
        tail = tail->next;
        listSize++;
    }
}

template<typename T>
void SLList<T>::pop_front() {
    if(!empty()){
        SLLNode<T>* temp = head;
        head = head->next;
        delete temp;
        listSize--;

        if(head == nullptr){
            tail = nullptr;
        }
    }  
}

template<typename T>
void SLList<T>::pop_back() {
    if(empty()){
        return;
    }
    if(listSize == 1){
        pop_front();
    }
    else{
        SLLNode* cur = head;
        while(!cur->next->next != nullptr){
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        tail = cur;
        listSize--;
    }
  
}