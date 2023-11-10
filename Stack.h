#pragma once

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack : public LinkedList<T> {
public:
    void Push(const T& value) {
        typename LinkedList<T>::Node* newNode = new typename LinkedList<T>::Node(value);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    void Pop() override {
        if (this->IsEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        typename LinkedList<T>::Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }


    T GetFront() const {
        return LinkedList<T>::GetFront();
    }
    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& Stack) {
        typename LinkedList<T>::ConstIterator it = Stack.cbegin();
        while (it != Stack.cend()) {
            os << *it << " ";
            ++it;
        }
        return os;
    }



};

#endif 
