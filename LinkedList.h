#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node* head;
    size_t size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void swap(LinkedList& other) {
        std::swap(head, other.head);
        std::swap(size, other.size);
    }

    friend void swap(LinkedList& lhs, LinkedList& rhs) {
        lhs.swap(rhs);
    }
    virtual ~LinkedList() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    LinkedList(const LinkedList& other) : head(nullptr), size(0) {
        Node* temp = other.head;
        while (temp) {
            Push(temp->data);
            temp = temp->next;
        }
    }

    LinkedList(LinkedList&& other) : head(other.head), size(other.size) {
        other.head = nullptr;
        other.size = 0;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            while (!IsEmpty()) {
                Pop();
            }

            Node* temp = other.head;
            while (temp) {
                Push(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) {
        if (this != &other) {
            while (!IsEmpty()) {
                Pop();
            }
            head = other.head;
            size = other.size;
            other.head = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void Push(const T& value) {
        if (this->IsEmpty()) {
            
            this->head = new Node(value);
        }
        else {
       
            Node* temp = this->head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
        this->size++;
    }


    virtual void Pop() {
        if (IsEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T GetFront() const {
        if (IsEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }
    

    class Iterator {
    protected:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    class ConstIterator {
    protected:
        const Node* current;

    public:
        ConstIterator(const Node* node) : current(node) {}

        const T& operator*() {
            return current->data;
        }

        ConstIterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const ConstIterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ConstIterator cbegin() const {
        return ConstIterator(head);
    }

    ConstIterator cend() const {
        return ConstIterator(nullptr);
    }
};

#endif // LINKED_LIST_H
