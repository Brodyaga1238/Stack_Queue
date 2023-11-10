#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue : public LinkedList<T> {
public:
    void Push(const T& value) {
        LinkedList<T>::Push(value);
    }

    void Pop() override {
    if (this->IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    typename LinkedList<T>::Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
    }

    T GetFront() const {
        return LinkedList<T>::GetFront();
    }
    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        typename LinkedList<T>::ConstIterator it = queue.cbegin();
        while (it != queue.cend()) {
            os << *it << " ";
            ++it;
        }
        return os;
    }

};
#endif 
